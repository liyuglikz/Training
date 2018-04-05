TEMPLATE = aux
TARGET = TextDemo

RESOURCES += TextDemo.qrc

QML_FILES += $$files(*.qml,true) \
             $$files(*.js,true)

CONF_FILES +=  TextDemo.apparmor \
               TextDemo.desktop \
               TextDemo.png

AP_TEST_FILES += tests/autopilot/run \
                 $$files(tests/*.py,true)               

OTHER_FILES += $${CONF_FILES} \
               $${QML_FILES} \
               $${AP_TEST_FILES}

#specify where the qml/js files are installed to
qml_files.path = /TextDemo
qml_files.files += $${QML_FILES}

#specify where the config files are installed to
config_files.path = /TextDemo
config_files.files += $${CONF_FILES}

INSTALLS+=config_files qml_files

