/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

/* General Partial MAR File Staged Patch Apply Failure Test */

function run_test() {
  gStageUpdate = true;
  setupTestCommon();
  gTestFiles = gTestFilesPartialSuccess;
  gTestFiles[11].originalFile = "partial.png";
  gTestDirs = gTestDirsPartialSuccess;
  setTestFilesAndDirsForFailure();
  setupUpdaterTest(FILE_PARTIAL_MAR);

  createUpdaterINI(true);

  // For Mac OS X set the last modified time for the root directory to a date in
  // the past to test that the last modified time is updated on all updates since
  // the precomplete file in the root of the bundle is renamed, etc. (bug 600098).
  if (IS_MACOSX) {
    let now = Date.now();
    let yesterday = now - (1000 * 60 * 60 * 24);
    let applyToDir = getApplyDirFile();
    applyToDir.lastModifiedTime = yesterday;
  }

  runUpdate(1, STATE_FAILED_UNEXPECTED_FILE_OPERATION_ERROR);
}

/**
 * Checks if the update has finished and if it has finished performs checks for
 * the test.
 */
function checkUpdateApplied() {
  if (IS_WIN || IS_MACOSX) {
    // Check that the post update process was not launched.
    do_check_false(getPostUpdateFile(".running").exists());
  }

  checkFilesAfterUpdateFailure(getApplyDirFile, true, false);
  checkUpdateLogContents(LOG_PARTIAL_FAILURE);
  waitForFilesInUse();
}
