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
