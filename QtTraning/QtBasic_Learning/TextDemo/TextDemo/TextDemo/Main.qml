import QtQuick 2.0
import Ubuntu.Components 1.1

/*!
    \brief MainView with a Label and Button elements.
*/

MainView {
    // objectName for functional testing purposes (autopilot-qt5)
    objectName: "mainView"

    // Note! applicationName needs to match the "name" field of the click manifest
    applicationName: "textdemo.username"

    /*
     This property enables the application to change orientation
     when the device is rotated. The default is false.
    */
    //automaticOrientation: true

    // Removes the old toolbar and enables new features of the new header.
    useDeprecatedToolbar: false

    width: units.gu(100)
    height: units.gu(75)

    Page {
        id: p1;
        title: i18n.tr("TextDemo")

        Column {
            spacing: units.gu(1)
            anchors {
                margins: units.gu(2)
                fill: parent
            }

            Row {
                id: r1;
                spacing: units.gu(3);
                anchors.margins: units.gu(2);

                Text {
                    id: text1;
                    text: i18n.tr("text1");
                }

                Text {
                    id: text2;
                    text: i18n.tr("Text2 :D");
                    color: "blue";
                    font.family: "Ubuntu";
                    font.pixelSize: 22;
                }

                Rectangle{
                    id: text3B;
                    width: units.gu(30);
                    height: 120;
                    color: "#737373";

                    Text {
                        width: parent.width;
                        height: parent.height;
                        id: text3;
                        text: i18n.tr("Text3 XD My Dear :DDDDDDDDDDDDDDDDDDDDDDDDD >.<");
                        //elide: Text.ElideMiddle;
                        //elide: Text.ElideLeft;
                        //elide: Text.ElideRight;
                        style: Text.Sunken;
                        styleColor: "Blue";
                        verticalAlignment: Text.AlignTop;
                    }
                }

            }
        }
    }
}


