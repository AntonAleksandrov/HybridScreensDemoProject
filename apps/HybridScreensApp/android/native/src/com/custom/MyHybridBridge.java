package com.custom;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.HybridScreensApp.HybridScreensApp;

import android.util.Log;

public class MyHybridBridge extends CordovaPlugin {
	private final String TAG = "MyHybridBridge";
	private final String ACTION_BIND_LISTENER = "ACTION_BIND_LISTENER";
	private final String ACTION_SET_NAVBAR_TITLE = "ACTION_SET_NAVBAR_TITLE";
	
	private CallbackContext listenerCallbackContext;

	public MyHybridBridge(){
		super();
		Log.d(TAG, "Constructing");
	}
    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
    	Log.d(TAG, "execute :: " + this.toString());
    	if (ACTION_BIND_LISTENER.equals(action)){
    		return bindListener(args, callbackContext);
    	} else if (ACTION_SET_NAVBAR_TITLE.equals(action)){
    		return setNavBarTitle(args, callbackContext);
    	}
    	
    	return false;
    }
    
    private boolean bindListener(JSONArray args, CallbackContext callbackContext) {
    	Log.d(TAG, "bindListener");
    	listenerCallbackContext = callbackContext;
    	PluginResult pluginResult = new PluginResult(PluginResult.Status.OK);
    	pluginResult.setKeepCallback(true);
    	callbackContext.sendPluginResult(pluginResult);
    	return true;
	}
    
    private boolean setNavBarTitle(JSONArray args, CallbackContext callbackContext) throws JSONException {
    	Log.d(TAG, "setNavBarTitle");
    	PluginResult pluginResult;
    	if (args.length()==1){
    		String title = args.getString(0);
    		((HybridScreensApp)cordova).updateTitle(title);
    		pluginResult = new PluginResult(PluginResult.Status.OK);
    	} else {
    		pluginResult = new PluginResult(PluginResult.Status.INVALID_ACTION);
    	}
    	
    	callbackContext.sendPluginResult(pluginResult);
    	return true;
	}

    public void reportEvent(JSONObject eventData){
    	Log.d(TAG, "reportEvent");
    	PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, eventData);
    	pluginResult.setKeepCallback(true);
    	listenerCallbackContext.sendPluginResult(pluginResult);
    }
}
