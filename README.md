# C++ LED Controller for the ReSpeaker 4mics_hat

The controller does not need any additional dependencies like WiringPi or libapa102. You only need the kernel headers to build it. I only have a RaspPi 3 B+ and the ReSpeaker 4mic_hat so I could not test on different configurations, but modifying it to work with others should be possible. This is my first foray into the world of RasPi development, so there may be a few rough edges.


# Build
You can either just add the LedController class to your project and use it or you can compile it with the test app, to see how it is used. (A Makefile will follow at some point)
```sh
$ gcc LedController.cpp LedController_Test.cpp -lstdc++
```
