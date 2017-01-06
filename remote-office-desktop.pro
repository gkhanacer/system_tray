TEMPLATE = subdirs

CONFIG+=ordered

# Project subdirectories
# app   -> application sourse
# tests -> applications unit tests
SUBDIRS = \
    app \
    tests

# If library project want to be created, this block will be activated.
#app.depends = src
#tests.depends = src

# All sub directories can access path in defaults.pri
OTHER_FILES += \
    defaults.pri
