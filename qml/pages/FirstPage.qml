import QtQuick 2.0
import Sailfish.Silica 1.0
import custom.Matrix 1.0

Page {
    id: page
    property int x_r: 0;
    property int y_r: 0;
    property int msize: 0
    property int i_: 0;
    property int j_: 0
    property int num_txt: 0
    property variant array: []
    property Matrix a
    // The effective value will be restricted by ApplicationWindow.allowedOrientations
    allowedOrientations: Orientation.All

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.fill: parent

        // PullDownMenu and PushUpMenu must be declared in SilicaFlickable, SilicaListView or SilicaGridView
        PullDownMenu {
            MenuItem {
                text: qsTr("Show Page 2")
                onClicked: pageStack.push(Qt.resolvedUrl("SecondPage.qml"))
            }
        }
        TextField {
            id: sizeField
            height: parent.height
            width: parent.width / 2
        }
        Button {
            anchors.left: sizeField.right
            width: parent.width/3
            text: "Enter size"
            onClicked: {
                msize = sizeField.text
                console.log(m.size)
            }
        }

        Matrix {
            id: m
            size: msize
        }


        // Tell SilicaFlickable the height of its content.
        //contentHeight: column.height

        // Place our content in a Column.  The PageHeader is always placed at the top
        // of the page, followed by our content.

//        Rectangle {
//            width: 150;
//            height: 150;
//            color: "red";
//            TextField {
//                text: String(1)
//                height: parent.height;
//                width: parent.width
//            }
//       }
//        Component.onCompleted: {
//            console.log("0:0 element")
//            console.log(m.getElement(0,0))
//            console.log("0:1 element")
//            console.log(m.getElement(0,1))
//            console.log("2:2 element")
//            console.log(m.getElement(2,2))
//        }

        Rectangle {
            id: root
            height: 500
            width: 500
            x: 100
            y: 100
            color: "transparent"
            property string sc: 'import QtQuick 2.0; import Sailfish.Silica 1.0;
                        Rectangle {
                            width: 150;
                            height: 150;
                            TextField {
                                id: '+ "txt_"+ String(page.num_txt) +'
                                text: ' + '"' + m.getElement(0,0) + '"' +';
                                height: parent.height;
                                width: parent.width;
                                }
                                color: "white";
                                Component.onCompleted:
                                {x = '+page.x_r+'; y = '+page.y_r+'; array['+ page.num_txt + '] = '+ "txt_"+ String(page.num_txt) +'}
                        }'
            Component.onCompleted: {
                m.size = 3
                var index = 0;
                for (var i = 0; i < 3; i++) {
                    j_ = 0;
                    for (var j = 0; j < 3; j++) {
                        index++;
                        //console.log("i:j = " + i_ + ":" + j_)
                        Qt.createQmlObject(sc, root, 'obj' + index);
                        //console.log("i:j = " + i_ + ":" + j_ + "DONE")
                        page.x_r+=160;
                        j_++;
                        page.num_txt++;

                    }
                    i_++;
                    page.x_r -= 3 * 160
                    page.y_r += 160;
                }
                i_ = 0;
                j_ = 0;
            }
        }
        Button {
            id: set_val
            text: "set value"
            width: parent.width/3
            anchors.bottom:  parent.bottom
            anchors.right: parent.right
            onClicked: {
                var index = 0;
                //console.log("SIZE : " + String(m.getSize()));
                for (var i = 0; i < m.getSize(); i++) {
                    for (var j = 0; j < m.getSize(); j++) {
                        m.setElement(String(array[index].text), j, i)
                        index++;
                    }
                }
            }
        }
        Button {
            id: pow
            text: "pow"
            width: parent.width/3
            anchors.bottom: parent.bottom
            anchors.right: set_val.left
            onClicked: {
                m.degree(2);
                var index = 0;
                console.log("Pow...")
                for (var i = 0; i < m.getSize(); i++) {
                    for (var j = 0; j < m.getSize(); j++) {
                        array[index].text = m.getElement(i, j);
                        index++;
                    }

                }
                console.log("Pow...DONE")
                console.log(m.getElement(0,0))
            }
        }
    }
}

