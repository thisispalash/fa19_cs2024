unsubmitted :(

The main problem was using the `fstreams` as member variables. Turns out, we need to open and close after every read. Maybe not, but that is how it works currently. Then, there was also appending the new balance rather than overwriting. It works now though, just barely lol.

Oh and as always, no error checking xD