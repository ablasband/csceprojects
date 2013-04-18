# treecp.py

import sys
import os
import shutil

# get args
FROM = sys.argv[1]
TO = sys.argv[2]
CUR = os.getcwd()

# check validity
if not os.path.exists(CUR + FROM):
	print "From argument is not valid: " + FROM + ".  Provide directories relative to the current directory."
	sys.exit(-1)

if not os.path.exists(CUR + TO):
	print "To argument is not valid: " + TO + ".  Provide directories relative to the current directory."
	sys.exit(-1)

# let user know whats up
print "Copying from: " + FROM + " to: " + TO + " in cwd: " + CUR + "..."

# do the copy
shutil.copytree(CUR + FROM, CUR + TO + "new/")

print "Copy complete!"
