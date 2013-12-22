
/* JavaScript content from js/main.js in folder common */
function wlCommonInit(){
    $.mobile.defaultPageTransition = "slide";
    
    $("[data-role='page']").on( "pagebeforeshow", function( event ) {
        var title = $(this).attr("data-title");
        MyHybridBridge.setNavBarTitle(title);
        
        if (title === "page1"){
            MyHybridBridge.updateNavBarLeftButton(null);
        } else {
            MyHybridBridge.updateNavBarLeftButton("Back");
        }
     });

    MyHybridBridge.bindListener(NativeEventsListener.onReceivedEvent);
}

/* JavaScript content from js/main.js in folder iphone */
// This method is invoked after loading the main HTML and successful initialization of the Worklight runtime.
function wlEnvInit(){
    wlCommonInit();
    // Environment initialization code goes here
}