# Chartboost Android SDK

The Chartboost SDK is the cornerstone of the Chartboost network. It provides the functionality for showing intersitials, Video, MoreApps pages, and tracking in-app purchase events. 

Here are the changes you need to be aware of in 5.0, whether you're upgrading from a previous SDK version or integrating for the first time.

* All public methods are now static, so rather than using instance calls (e.g. "this.cb") you can use the class name to call methods' names (e.g. Chartboost.onCreate()).
* SDK intialization API name and its parameters are changed.
* ChartboostDelegate is not an interface anymore, rather it is an abstract class. This means you don't need to know ahead of time (or implement) the delegate callbacks that will be needed.
* New activity callbacks are added. `onPause()` and `onResume()`. 
* Java API docs are provided along with SDK and a sample app (CBSample).


### Usage

Integrating Chartboost takes a few easy steps:

1. Make sure your app fits the minimum requirements:
     - Minimum API level 9 (Android OS 2.3)
     - Required permission: `android.permission.INTERNET`
     - Required permission: `android.permission.ACCESS_NETWORK_STATE`
     - Optional (recommended) permissions: `android.permission.WRITE_EXTERNAL_STORAGE`, `android.permission.ACCESS_WIFI_STATE`

2. Add the `chartboost.jar` file to your `libs` directory.
     - If you don't have a `libs` directory, create one and add the .jar file to it
     - Optionally add `chartboost.jar.properties` and the `doc` directory to `libs` to get javadocs in your IDE

3. Add the Google Play Services library as a dependency of your project.
     - The Google Play Services library has its own set of integration instructions, including additions to your Android Manifest and Proguard configuration
     - You can follow the setup instructions outlined by Google at the [Google Developer website](https://developer.android.com/google/play-services/setup.html)

4. **Note**: Add the following parameter to the `<application>` tag in your `AndroidManifest.xml` file to ensure smooth transitions and video playback:

		android:hardwareAccelerated="true"
    
5. Import the Chartboost SDK into any activity that uses Chartboost

		import com.chartboost.sdk.*;


6. If any activity in which you display Chartboost impressions can rotate between different orientations, you should add the following attribute to the activity in the `AndroidManifest.xml` file in order to achieve smooth video playback during orientation changes:

		android:configChanges="keyboardHidden|orientation|screenSize"


7. Intialize the Chartboost SDK in your launcher activity class so that the Chartboost callbacks or API calls can be made.  
There are two choices for initialization: 
	* You can let the SDK handle this for you by simply extending `ChartboostActivity`. This removes the need for you to override any activity lifecycle methods such as `onCreate`, so you can simply call `Chartboost.OnCreate()`.  **SKIP TO STEP 11**.
	* You can extend the application's main Activity explicitly (continue following steps 7 through 8).  See example:
	
			public class <Your class name> extends Activity {
            
			@Override
			public void onCreate() {
				super.onCreate();
				Chartboost.startWithAppId(this, appId, appSignature);
				/* Optional: If you want to program responses to Chartboost events, supply a delegate object here and see step (10) for more information */
				//Chartboost.setDelegate( <Valid Delegate Object> );
				Chartboost.onCreate(this);
				}   
			}
	* Watch for this error as it indicates that the SDK was not initialized properly: `Exception: Initialization error`.
8. Add the following code to your activity's `onStart()`, `onPause()`, `onResume()` ,`onStop()`, `onDestroy()`, and `onBackPressed()` methods:

        @Override
        public void onStart() {
            super.onStart();
            Chartboost.onStart(this);
        }

        @Override
        public void onResume() {
            super.onResume();
            Chartboost.onResume(this);
        }

        @Override
        public void onPause() {
            super.onPause();
            Chartboost.onPause(this);
        }
        
        @Override
        public void onStop() {
            super.onStop();
            Chartboost.onStop(this);
        }

        @Override
        public void onDestroy() {
            super.onDestroy();
            Chartboost.onDestroy(this);
        }

        @Override
        public void onBackPressed() {
            // If an interstitial is on screen, close it.
            if (Chartboost.onBackPressed())
                return;
            else
                super.onBackPressed();
        }
 

9. **Important**: All your interstitial, MoreApps, InPlay and Video calls are static. You *must* pass in the location string to every call, `null` is no longer available. If you don't pass in the location, the SDK won't fetch any ads. You can use the `CBLocation` interface class to get a list of default location constants as well as define your own.  Once a location is used, it will be added to your dashboard where you can customize settings for it.
	* Example Ad Calls:
	
			// Interstitials
			Chartboost.cacheInterstitial(CBLocation.LOCATION_DEFAULT);
			Chartboost.showInterstitial(CBLocation.LOCATION_DEFAULT);
			
			// Video
			Chartboost.showRewardedVideo(CBLocation.LOCATION_GAMEOVER);
			Chartboost.cacheRewardedVideo(CBLocation.LOCATION_GAMEOVER);
10. Back in step (7) you may have noticed `Chartboost.setDelegate(delegate)`.  **Note**: we do not pass '*null*' or a delegate object to an overridden `onCreate()` anymore to create delegates, since it has its own class method now.  Call the method *before* calling `Chartboost.onCreate(this)` during initialization. 
    * The parameter it takes is a *delegate object*, which allows you to respond to the events you are interested in by overriding the methods of your choice.  Simply supply an object of the abstract class `ChartboostDelegate` as the parameter:
    
            private ChartboostDelegate delegate = new ChartboostDelegate() {
            //Override the Chartboost delegate callbacks you wish to track and control
            }; 
            
    * This new method eliminates the need to extend from ChartboostDefaultDelegate as in previous versions of the SDK.
    
11. You can choose to have your activities that use Chartboost extend from `ChartboostActivity` instead of Activity.  Read more about this in our README.md.
**Important**: If you use this integration method, you must initialize Chartboost with the method `Chartboost.startWithAppId()` *before* calling `super.onCreate()`. If you do not, an exception will be thrown, as the SDK needs to be initialized first before the SDK calls `Chartboost.onCreate()` internally. Example:

		public class <Your class name> extends ChartboostActivity {
			@Override
			public void onCreate() {
				Chartboost.startWithAppId(this, appId, appSignature);
				super.onCreate();
				ShowMeTheMoney();
			}
		}
 
12. If you plan on using Proguard, add the following to your *proguard.cfg* file (also make sure you follow Proguard instructions for the Google Play Services library):

		-keep class com.chartboost.** { *; }


### CBAnalytics
 
 The CBAnalytics product tracks events related to In-App Purchases (IAP) made by a user once the game is installed. It provides the developer with more granular information about the IAP events. In this release it only supports `In-App Purchasing` but more event types will be added soon.
        
* **In-App Purchasing:**
      * In-App Purchase lets you sell a variety of items directly within your free or paid app, including premium content, virtual goods, and subscriptions. The Chartboost SDK provides an API to track these purchases by sending the information to the SDK, and supports events that go through `GooglePlayStore` and `Amazon`. Check out the sample app on how to retrieve the data and send it to SDK. 

      * If upgrading from a previous Chartboost SDK version and you are using `trackInAppPurchaseEvent(EnumMap<CBIAPPurchaseInfo, String> map, CBIAPType iapType)` method to send InApp Purchase details, the examples below achieve the same result.

*  **Examples:**

`Google`

		CBAnalytics.trackInAppGooglePlayPurchaseEvent("xxx-title",
						"xxx-description",
						"$0.99",
						"USD",
						"xxx-id",
						"xxx-data",
						"xxx-signature");

`Amazon`

		CBAnalytics.trackInAppAmazonStorePurchaseEvent("xxx-title",
						"xxx-description",
						"$0.99",
						"USD",
						"xxx-id",
						"xxx-userId",
						"xxx-token");

### Example Code
Check out the sample code inside the `CBSample` project, found in the CBSample folder of this download.


### Questions?
We want to your SDK integration be as smooth as possible, so that you can spend more of your time developing awesome games!  If you encounter any issues, do not hesitate to contact our support team at [support@chartboost.com](mailto:support@chartboost.com) and we will be happy to help.
