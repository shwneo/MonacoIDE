import os
PWD = os.getcwd()

MSVC_OPTIONS = ['/Zi','/nologo','/W3','/WX-','/O2','/Oi','/Oy-','/GL','/D"WIN32"','/D"NDEBUG"','/D"_UNICODE"','/D"_UNICODE"','/Gm-',
				'/EHsc','/MD','/GS','/Gy','/DUNICODE','/fp:precise','/Zc:wchar_t']
MSVC_DLL_OPTIONS = ['/D_WINDLL','/D_USRDLL']
Building_x86 = Environment(TARGET_ARCH='x86')
BUILDING_OPTIONS = [MSVC_OPTIONS,MSVC_DLL_OPTIONS]
SCINTILLA_DIR = PWD + '/code/scintilla/win32/'
BOOST_DIR = PWD + '/code/boost/'
SDK_PATH = PWD + '/depends/sdk'
DEPENDS_PATH = PWD + '/depends/'
DEPENDS_INC_PATH = DEPENDS_PATH + '/include/'
DEPENDS_LIB_PATH = DEPENDS_PATH + '/lib/'
Building_x86.Append(CPPFLAGS=[MSVC_OPTIONS])
Building_x86.Append(CPPPATH=[DEPENDS_INC_PATH])
Building_x86.Append(LIBPATH=DEPENDS_PATH + '/lib')


BOOST_INC_DIR = BOOST_DIR
BOOST_LIB_DIR = BOOST_DIR + '/stage/lib/'

SDK_LIB_PATH = SDK_PATH + '/win32/lib'
SDK_INC_PATH = SDK_PATH + 'include'

Export('BUILDING_OPTIONS')
Export('SCINTILLA_DIR')
Export('Building_x86')
Export('BOOST_DIR')
Export('SDK_PATH')
Export('MSVC_DLL_OPTIONS')


SConscript([SCINTILLA_DIR + 'SConscript', 'code/tinyxml/SConscript', BOOST_DIR + 'SConscript', 'components/SConscript'])