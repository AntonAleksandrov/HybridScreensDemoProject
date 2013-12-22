
/* JavaScript content from js/MyHybridBridge.js in folder common */
var MyHybridBridge = (function() {
	var PLUGIN_NAME 						= "MyHybridBridge";
	var ACTION_BIND_LISTENER 				= "ACTION_BIND_LISTENER";
	var ACTION_SET_NAVBAR_TITLE 			= "ACTION_SET_NAVBAR_TITLE";
	var ACTION_UPDATE_NAVBAR_LEFT_BUTTON 	= "ACTION_UPDATE_NAVBAR_LEFT_BUTTON";

	var logger = WL.Logger.create({	pkg : "MyHybridBridge" });
	logger.log("Initializing");

	this.bindListener = function(listener) {
		logger.log("bindListener");
		cordova.exec(listener, listener, PLUGIN_NAME, ACTION_BIND_LISTENER,	[]);
	};

	this.setNavBarTitle = function (title)	{
		logger.log("setNavBarTitle");
		cordova.exec(null, null, PLUGIN_NAME, ACTION_SET_NAVBAR_TITLE, [title]);
	};
	
	this.updateNavBarLeftButton = function(title) {
		logger.log("updateNavBarLeftButton");
		cordova.exec(null, null, PLUGIN_NAME, ACTION_UPDATE_NAVBAR_LEFT_BUTTON, [title]);
	};

	return this;
}());
