import QtQml 2.0
//import QtQuick 2.2
import OutQross.Android 0.1

OutQrossItem {

    Activity {
        id: mainactivity
        Component.onCompleted: setViewContent(layout);
    }

    RelativeLayout {
        id: layout
        Button {
            text: "Hello World!"
        }
    }

}
