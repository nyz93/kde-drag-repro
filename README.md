Executing `make` will open a nested kwin_wayland session, start the dnd target application, an instance of dolphin and a tool that writes to the clipboard with `KSystemClipboard::setMimeData`

To trigger the bug first drag a file or directory from dolphin onto the test application, then switch back to dolphin and then again to the test application and observe how the log contains an extra line of "DRAG MOTION" after the "FOCUSED" line.

Executing `make without_clipboard` will not run the clipboard tool and following the above steps will not trigger the drag motion events 
