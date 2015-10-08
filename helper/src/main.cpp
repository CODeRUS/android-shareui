#include <stdio.h>
#include <sys/stat.h>
#include <QProcess>
#include <QStringList>

#include <QFile>
#include <QTextStream>

#include <sys/types.h>
#include <unistd.h>

#include <QCoreApplication>
#include <QTimer>
#include "dbusmain.h"

int main(int argc, char *argv[])
{
    //::setgid(0);
    //::setuid(0);
    ::chroot("/opt/alien");
    ::chdir("/");

    // Hacka hacking hacky-hacky hacked hacku hacka hack.

    qputenv("WAYLAND_DISPLAY", "../../display/wayland-0");
    qputenv("SHELL", "/bin/bash");
    qputenv("EXECSHELL", "/system/bin/sh");
    qputenv("ALIEN_KEYSTORE", "/data/keystore");
    qputenv("ALIEN_LOG_OUTPUT", "true");
    qputenv("MEDIA_STORAGE", "/data/media");
    qputenv("DOWNLOAD_CACHE", "/cache");
    qputenv("ALIEN_ID", "LV-426");
    qputenv("LC_ALL", "C");
    qputenv("USER", "root");
    qputenv("LD_LIBRARY_PATH", "/system/vendor/lib:/system/lib:/vendor/lib:/system_jolla/lib:");
    qputenv("SYSTEM_USER_HOME", "/home/nemo");
    qputenv("ALIEN_SHUTDOWN_ON_REBOOT", "true");
    qputenv("ALIEN_RESTART_CRITICAL_SVC", "false");
    qputenv("USERNAME", "root");
    qputenv("SYSTEM_USER_ID", "100000");
    qputenv("ANDROID_SOCKET_DIR", "/run/user/1000/alien/socket");
    qputenv("BOOTCLASSPATH", "/system/framework/core.jar:/system/framework/core-junit.jar:/system/framework/bouncycastle.jar:/system/framework/ext.jar:/system/framework/framework.jar:/system/framework/framework_ext.jar:/system/framework/android.policy.jar:/system/framework/services.jar:/system/framework/apache-xml.jar");
    qputenv("MAIL", "/var/mail/root");
    qputenv("PATH", "/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/sbin:/usr/sbin:/root/bin");
    qputenv("SYSTEM_USER_LANG", "ru_RU.utf8");
    qputenv("ANDROID_DATA", "/data");
    qputenv("PWD", "/");
    qputenv("LANG", "C");
    qputenv("ALIEN_MEDIASCAN_PATHS", "/home/nemo:/media");
    qputenv("SYSTEM_USER_NAME", "nemo");
    qputenv("ALIEN_PIXELFORMAT", "BGRA32");
    qputenv("ANDROID_ASHMEM_DIR", "/run/user/1000/alien/ashmem");
    qputenv("SHLVL", "1");
    qputenv("HOME", "/root");
    qputenv("ALIEN_GEOMETRY", "540x960");
    qputenv("ANDROID_ROOT", "/system");
    qputenv("EXTERNAL_STORAGE", "/home/nemo/android_storage");
    qputenv("LOGNAME", "root");
    qputenv("CLASSPATH", "/system/framework/am.jar");
    qputenv("DBUS_SESSION_BUS_ADDRESS", "unix:path=/run/user/100000/dbus/user_bus_socket");
    qputenv("ANDROID_LOG_TAGS", "*:e");
    qputenv("SYSTEM_USER_XDG_RUNTIME_DIR", "/run/user/100000");
    qputenv("XDG_RUNTIME_DIR", "/run/user/1000");
    qputenv("DISPLAY", ":0.0");

/*
    qputenv("DBUS_SESSION_BUS_ADDRESS", "unix:path=/run/user/100000/dbus/user_bus_socket");

    QByteArray ANDROID_ROOT("/system");
    QByteArray ANDROID_DATA("/data");

    qputenv("LD_LIBRARY_PATH", "/system/vendor/lib:/system/lib:/vendor/lib:/system_jolla/lib:");
    qputenv("SYSTEM_USER_LANG", "C");

    qputenv("ANDROID_ROOT", ANDROID_ROOT);
    qputenv("ANDROID_DATA", ANDROID_DATA);

    QFile init("/system/script/start_alien.sh");
    if (init.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&init);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("export BOOTCLASSPATH=")) {
                line=line.mid(21).replace("$FRAMEWORK", "/system/framework");
                qputenv("BOOTCLASSPATH", line.toUtf8());
            }
        }
    }
    else {
        return 0;
    }

    QFile envsetup("/system/script/platform_envsetup.sh");
    if (envsetup.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&envsetup);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("export ALIEN_ID=")) {
                line=line.mid(16);
                qputenv("ALIEN_ID", line.toUtf8());
            }
        }
    }
    else {
        return 0;
    }

    qputenv("CLASSPATH", "/system/framework/am.jar");
*/

/*
    QStringList args;
    args << "/system/bin" << "com.android.commands.am.Am" << "start";
    args << "-a" << "android.intent.action.SEND";
    args << "-t";

    if (argc == 3) {
        args << QString(argv[2]);
        args << "--eu";
        args << "android.intent.extra.STREAM";
    }
    else if (argc == 2) {
        args << "text/*";
        args << "--es";
        args << "android.intent.extra.TEXT";
    }
    else {
        return 0;
    }

    args << QString(argv[1]);

    QProcess proc;
    proc.startDetached("/system/bin/app_process", args);

    return 0;
*/

    QCoreApplication app(argc, argv);
    DBusMain *bus = new DBusMain();
    QTimer::singleShot(100, bus, SLOT(start()));
    return app.exec();
}


