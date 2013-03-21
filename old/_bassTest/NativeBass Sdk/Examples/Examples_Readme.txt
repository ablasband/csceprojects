

	HOW TO RUN EXAMPLES ?


FIRST STEP
----------

To run the examples, you need at least Java 1.5 installed.

REMARK
Java 1.5 is requiered to run the examples (examples are written with Java 1.5).
BUT NativeFmodEx is FULLY compatible with Java 1.4.


[WIN32]
You can now run any examples using the appropriate batch files (*.bat).

[MAC]
The script to run Mac examples is in runBass.sh.
To use it, open a terminal and go to the folder that contains examples, then write this :
  sh runBass.sh <example>

ie
  sh runBass.sh BassTest


TROUBLES
--------
If Java is not recognized, add it in your PATH or replace java in the script by the full path of java (ie 'c:/java/bin/java' instead of 'java').


PARTICULAR EXAMPLES
-------------------

  [Contest]
Requiere a music file to play.
Either put BASS.WAV here or edit 'ConTest.bat' and change the file name.

  [RecTest]
See 'LiveSpec' note.

  [LiveSpec]
This example is a spectrum analyser using the record output.
To record something, you need to play a music somewhere (like a music player, a game ...).
If you have some troubles under Windows (ie record nothing), open 'Recording Panel' of Windows enable wave output.

  [Plugins]
To obtain BASS Plugins, go to http://www.un4seen.com/.
Then, extract the bass***.dll plugin here.


