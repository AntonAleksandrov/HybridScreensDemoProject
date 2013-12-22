var NativeEventsListener = (function() {
	var logger = WL.Logger.create({ pkg : "NativeEventsListener" });
	logger.log("Initializing");

	this.onReceivedEvent = function(eventData) {
		logger.log("onReceivedEvent :: eventData :: " + JSON.stringify(eventData));
		
		var eventHandler = function(){};

		switch (eventData.eventType){
			case "segmentedClick":
				eventHandler = processSegmentedClickEvent;
				break;
			case "navBarLeftButtonClicked":
				eventHandler = processNavBarLeftButtonClicked;
				break;
			default: 
				logger.log("onReceivedEvent :: unrecognized eventType");
		}
		eventHandler(eventData);
	};
	
	function processSegmentedClickEvent(eventData){
		var pageId = "#page" + eventData.pageIndex;
		logger.log("processSegmentedClickEvent :: pageId :: " + pageId);
		$.mobile.changePage(pageId, {
			reverse: pageId === "#page1" ? true: false
		});
	}
	
	function processNavBarLeftButtonClicked(eventData){
		logger.log("processNavBarLeftButtonClicked");
		$.mobile.changePage("#page1", {
			reverse: true
		});

	}

	return this;
}());
