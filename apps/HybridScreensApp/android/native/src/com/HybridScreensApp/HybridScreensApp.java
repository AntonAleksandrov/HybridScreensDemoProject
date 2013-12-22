package com.HybridScreensApp;

import org.json.JSONException;
import org.json.JSONObject;

import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;

import com.custom.MyHybridBridge;
import com.worklight.androidgap.WLDroidGap;

public class HybridScreensApp extends WLDroidGap implements OnClickListener {
	
	@Override
	public void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		setTitle("page1");
	}
	
	/**
     * onWLInitCompleted is called when the Worklight runtime framework initialization is complete
     */
	@Override
	public void onWLInitCompleted(Bundle savedInstanceState){
		super.loadUrl(getWebMainFilePath());
		
		View nativeControls  = LayoutInflater.from(this).inflate(R.layout.native_layout, null);
		this.root.addView(nativeControls, 0);
		findViewById(R.id.page1button).setOnClickListener(this);
		findViewById(R.id.page2button).setOnClickListener(this);
		findViewById(R.id.page3button).setOnClickListener(this);
	}
	
	public void onClick(View v) {
		Log.d(TAG, "onClick");
		JSONObject eventData = new JSONObject();
		
		MyHybridBridge bridge = (MyHybridBridge) appView.pluginManager.getPlugin("MyHybridBridge");
		String pageId = (String) v.getTag();
		try {
			eventData.put("eventType", "segmentedClick");
			eventData.put("pageIndex", pageId);
		} catch (JSONException e) {
			e.printStackTrace();
		}
		
		bridge.reportEvent(eventData);
	}

	public boolean onCreateOptionsMenu(Menu menu) {
		return false;
	}
	
	public void updateTitle(final String title){
		runOnUiThread(new Runnable() {
			@Override
			public void run() {
				setTitle(title);
			}
		});
	}

}



