Android Change Log
==================

Version 5.1.3 *(2015-03-16)*
----------------------------
Fixes:

- Fix Seeing duplicate calls for showInterstitial on Unity Android. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1551](https://chartboost.atlassian.net/browse/PUB-1551))
- Fix Seeing duplicate calls for showRewardedVideo on Unity Android. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1554](https://chartboost.atlassian.net/browse/PUB-1554))

Improvements:

Version 5.1.2 *(2015-03-04)*
----------------------------

Features:

Fixes:

- Fix didDismissInterstitial and didDismissRewardedVideo not executing on Android. #([@JonHummel](https://github.com/JonHummel) / [PUB-1495](https://chartboost.atlassian.net/browse/PUB-1495))
- Fix didCacheInterstitial not being called if an ad was already cached at the location. #([@gonch](https://github.com/gonch) / [PUB-1494](https://chartboost.atlassian.net/browse/PUB-1494))

Improvements:

Version 5.1.1 *(2015-02-20)*
----------------------------

Features:

Fixes:

- Fix for devkit engine issue on video playback. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1249](https://chartboost.atlassian.net/browse/PUB-1249))
- Fix video crash issue on crash exception. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1323](https://chartboost.atlassian.net/browse/PUB-1323), [PUB-1358](https://chartboost.atlassian.net/browse/PUB-1358), [PUB-1359](https://chartboost.atlassian.net/browse/PUB-1359)) 
- Fixes for video issues. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1396](https://chartboost.atlassian.net/browse/PUB-1396), [PUB-1363](https://chartboost.atlassian.net/browse/PUB-1363), [PUB-1361](https://chartboost.atlassian.net/browse/PUB-1361))

Improvements:

Version 5.1.0 *(2014-12-09)*
----------------------------

Features:

Fixes:

- Fix Android SDK 5.0.3 crashing on Video Interstitial due to NullPointerException. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1046](https://chartboost.atlassian.net/browse/PUB-1046))
- Fix Android SDK: Proper error enum names. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1034](https://chartboost.atlassian.net/browse/PUB-1034))
- Fix MoreApps Unity 5.0.2 and 5.0 for Android doesn't work. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1045](https://chartboost.atlassian.net/browse/PUB-1045))
- Fix Unity: Parity Android error enum. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1045](https://chartboost.atlassian.net/browse/PUB-1045))
- Fix SDK sends "custom-id" but ad server expects "custom_id" field. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1053](https://chartboost.atlassian.net/browse/PUB-1053))
- Fix See black screen and not video when reward/get has been modified. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1087](https://chartboost.atlassian.net/browse/PUB-1087))
- Fix Android Video: Black screen for invalid response. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1089](https://chartboost.atlassian.net/browse/PUB-1089))
- Fix Rewarded Video request freezes app if pre-roll popup gets closed after watching at least one video. #([@sat2eesh](https://github.com/sat2eesh) / [PUB-1101](https://chartboost.atlassian.net/browse/PUB-1101))

Improvements:

Version 5.0.4 *(2014-11-06)*
----------------------------

- Fix autocaching ads.
- New API: isAnyViewVisible() which can used to check if any chartboost ads are visible.
- Bug fixes and stability improvements for video, interstitial and inplay.

Version 5.0.3 *(2014-09-30)*
----------------------------

- Fix video playback codec support for low end android devices.
- 'willDisplayVideo' delegate callback added when the video is about to be displayed both for rewarded and interstitial video.
- Minor bug fixes and improvements.

Version 5.0.2 *(2014-09-10)*
----------------------------

- Fix for video where certain OEM devices video complete calls where not sent out properly.
- Minor bug fixes and patches.

Version 5.0.1 *(2014-09-05)*
----------------------------

- Fix for flickering issue for video on 2.3 devices on native sdk.
- Fix for unity plugin caused calling the onBackPressedEvent from a non-UI Thread.
- Fix for a race condition where concurrent ad request of same type can be sent for same location.
- Fix for a crash when using impression activities.
- Some minor fixes.

Version 5.0.0 *(2014-09-02)*
----------------------------

- API change: Chartboost methods are now called statically, and some of the method names and structures have changed. Please see the sample app or readme for updated integration instructions.
- Updated MoreApps page (graphics and functionality).
- New ad products: video interstitials and rewarded videos.
- Updated sample project.
- Many delegate methods moved to setter and getter functions.
- CBPostInstallTracking renamed to CBAnalytics.
- Added impression auto-caching feature.
- Removed unnecessary settings.
- Bugfixes and stability improvements.
- Upgrading to 5.0 Google Play Services library.
- Some major fixes and cleanups on SDK and libs being used to reduce the jar size.

Version 4.1.2 *(2014-08-14)*
----------------------------

- Fix: Random crash that happens on 4.1.1 builds.

Version 4.1.1 *(2014-06-10)*
----------------------------

- Fix: Crash while retrying request during network change.
- Fix: Crash while caching interstital before calling onStart().
- Fix: Crash when filesystem data unavailable.
- Tracking overload if network failure happens.

Version 4.1.0 *(2014-06-10)*
----------------------------

- New product - Post Install Analytics Tracking. Exposing In-App purchasing API for developers to track GooglePlay, Amazon and  ChartBoost Store in-app purchases. For more info go through ReadMe section of PostInstallTracking.
- New product - Tracking. This product is mainly used to log session events, user events, system events and debug events that is recorded across SDK and sent to server.
- New update:
	 a) Carrier information like Carrier name,MCC,MNC,ISO and phone type is sent in every API request.
 	 b) jb flag is sent on every request to determine if the device is more likely jailbroken or rooted device.
	 c) CBLocation constants are provided to developers. Its a default set of location constants which they can use during impression calls. 	 
- Deprecated methods (Will be removed in the future releases)
	a) startSession() - SDK will be internally handling and tracking the session calls. 
	b) clearImageCache() - Use clearCache() method which will perform clearImageCache() operation internally.
	c) setFramework() - It was removed in the previous release which cause some chaos, so we are just adding it as a deprecated method for now.
- SDK Improvements
	a) Ultra fast Networking library for asynchrounous networking. (Volley + OkHttp Square)
	b) All Impression classes are now more structurally organized.
	c) All Impressions are grouped into their own packages, so that it will be more helpful when we move to dependency injection structure. 
	d) File Caching and network reachability is centralised across SDK use.
	e) RequestManager module integrated with the new custom networking library for more seamless and lossless chartboost api calls.
	f) Some clickable elements in impressions now have a pressed effect to improve user experience.

Version 4.0.0 *(2014-03-17)*
----------------------------

- New Feature: Added Google Play Services advertising ID tracking, please see updated integration instructions in the documentation.
- New Feature: Different close button images for each orientation.
- New Feature: Error reasons for delegate failure methods.
- Animation performance improved -- we recommend you target Android 4.0+ for best performance.
- New Feature: Age gate for impression links -- see the documentation of the new delegate method `shouldPauseClickForConfirmation()`.
- Change: We've reorganized the SDK so that all Chartboost properties and settings are accessed and changed through the new `CBPreferences` class.
- New Feature: Control over logging that can help us diagnose any issues that you are having, see `CBPreferences.setLoggingLevel()`.
- Renamed `didFailToLoadUrl` delegate method to `didFailToRecordClick` in order to better describe all possibilities.
- Fixed rare bug that caused incorrect ad sizes.
- `CBAnalytics` is no longer available.

Version 3.4.0 *(2013-11-20)*
----------------------------

- New feature: now handles high res interstitial assets!

Version 3.3.0 *(2013-09-12)*
----------------------------

- New Feature: `ChartboostActivity` and `ChartboostNativeActivity` are simple alternatives to implementing Chartboost in your app.  Simply extend your activities from either class (depending on whether you use native activities or not), provide the app ID and signature, and you're done!
- Changed documentation to suggest calling `Chartboost.startSession()` in your activity's `onStart()` method.

Version 3.2.3 *(2013-06-24)*
----------------------------

- New Feature: `ChartboostDefaultDelegate` is a new abstract class that serves as a `ChartboostDelegate`. Extending from this instead will allow you to skip overriding the methods you are not interested in, at the expense of not being able to inherit from your own base class. The default implementation returns true for any method that returns a boolean in the delegate.
- New delegate method: `didFailToLoadUrl()` is called when the result of a click in an impression fails to load.
- Added exceptions to warn you if you have forgotten to properly exclude Chartboost from your proguard using the line `-keep class com.chartboost.sdk.** { *; }`.
- Change: Simultaneous identical interestitial or more apps request attempts will fail immediately. However, simultaneous interstitial requests with different locations are fine.
- Fix allowing Chartboost servers to differentiate buggy Android 2.x devices that all share the same `ANDROID_ID`.
- Fixed an infrequent HTTP connection error during image downloads.
- Fixed bug where if the network is lost while viewing the more apps page, a click would cause a progress bar to hang forever.
- Fixed edge case crashes related to caching images.

Version 3.2.2 *(2013-06-03)*
----------------------------

- Change: Method `Chartboost.orientation()` is now called `getOrientation()`.
- Add ability to disable animations and fixed animation type none.
- Fixed memory leak that could sometimes occur with the activity impressions setting.

Version 3.2.1 *(2013-04-23)*
----------------------------

- Removed dependence of sensor listener unless orientation is overridden.
- Removed all dependencies on `AsyncTask`, ensuring full compatibility with multithreaded apps.
- Fixed bug where screen stayed dark after closing interstitials on certain problem devices (including 4.1.2 Nexus S and Nexus 10).
- Fixed interference with game-rate sensor listeners on certain problem devices (including 2.3.x Galaxy S1 and Galaxy S2).
- Fixed crash when `cacheInterstitial()` was called off the UI thread.

Version 3.2.0 *(2013-03-30)*
----------------------------

- New method: `Chartboost.showMoreAppsData()` allows you to get raw JSON information about your more apps page so that you can display it however you like.
- Change: Show impression calls will immediately fail (and call delegate method) if an impression is already visible.
- Stopped delegate method `shouldDisplayLoadingViewForMoreApps()` from being fired when showing interstitials.
- Fixed delegate method `shouldRequestMoreApps()` was not being called as specified.

Version 3.1.6 *(2013-03-21)*
----------------------------

- Fixed harmless Lint error about invalid package reference (also no longer necessary to include `-dontwarn java.lang.management.**` in your proguard configuration).
- Fixed memory leak involved in using Chartboost in multiple subsequent activities.
- Fail gracefully in low memory situations.
- Added ability to suppress off-thread method calling exceptions for certain unusual use cases.
