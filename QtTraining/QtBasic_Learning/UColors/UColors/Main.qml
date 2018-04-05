    import QtQuick 2.0
    import Ubuntu.Components 1.1
      
    /*!  
        \brief MainView with a Label and Button elements.  
    */  
      
    MainView {  
        // objectName for functional testing purposes (autopilot-qt5)  
        objectName: "mainView"  
      
        // Note! applicationName needs to match the "name" field of the click manifest  
        applicationName: "ubuntucolors.liu-xiao-guo"  
      
        width: units.gu(60)  
        height: units.gu(85)  
      
        Page {  
            title: i18n.tr("ubuntucolors")  
      
            ListModel {  
                id: mymodel;  
            }  
      
            ListView {  
                anchors.fill: parent  
                model: mymodel  
                delegate: ListItem {  
                    Rectangle {  
                        anchors.fill: parent  
                        color: value  
                    }  
                    Label {  
                        anchors.centerIn: parent  
                        text: name  
                        fontSize: "large"  
                    }  
                }  
            }  
      
            Component.onCompleted: {  
                var keys = Object.keys(UbuntuColors);  
                for(var i = 0; i < keys.length; i++) {  
                    var key = keys[i];  
                    // prints all properties, signals, functions from object  
                    var type = typeof UbuntuColors[key];  
                    if ( type !== 'function' &&  
                         key.indexOf("Gradient") === -1 &&  
                         key !== "objectName") {  
                        //                    console.log("type: " + type)  
                        console.log(key + ' : ' + UbuntuColors[key]);  
                        var color = "" + UbuntuColors[key];  
                        console.log("color: " + color)  
                        mymodel.append({"name": key, "value": color});  
                    }  
                }  
            }  
        }  
    }  
