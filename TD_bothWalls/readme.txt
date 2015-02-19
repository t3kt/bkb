
There are three Geometry versions of the "bowl" wall here.
Each has a different UV map so you can select which model displays your footage the best.  An automatic switcher might be handy here but I suggest filling a bin with one of these three sizes:

2560x720, 1920x1080 or 1280x720

Then pipe the bin output to the model that matches (null before switch, which has a movieTest_reference image).  Make sure the Render TOPs are only rendering this particular model.

Cameras stay put.
Two 1280x720 renders are placed next to each other and finally a mask over this.  Final outout is 2560x720.


I just added the Boulder wall as well.  There was a problem with the model but we found a quick solution for Touch Designer.  The UV map is for 3840x720.  You can render out something smaller and just scale it back up when adding it to the model.  Just try keeping the same aspect ratio (5.3333 to 1).

