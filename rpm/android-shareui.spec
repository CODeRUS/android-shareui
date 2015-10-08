Name:       android-shareui

%{!?qtc_qmake:%define qtc_qmake %qmake}
%{!?qtc_qmake5:%define qtc_qmake5 %qmake5}
%{!?qtc_make:%define qtc_make make}
%{?qtc_builddir:%define _builddir %qtc_builddir}
Summary:    Share to Android
Version:    0.1.0
Release:    1
Group:      Qt/Qt
License:    WTFPL
URL:        http://example.org/
Source0:    %{name}-%{version}.tar.bz2
Requires:   aliendalvik
Requires:   sailfish-version >= 1.1.9
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(nemotransferengine-qt5)

%description
Share to Android plugin

%prep
%setup -q -n %{name}-%{version}

%build

%qtc_qmake5 

%qtc_make %{?_smp_mflags}

%install
rm -rf %{buildroot}
%qmake5_install

%files
%defattr(-,root,root,-)
%{_bindir}/*
/usr/share/dbus-1/system-services/*.service
/lib/systemd/system/*.service
/etc/dbus-1/system.d/*.conf
%{_libdir}/nemo-transferengine/plugins/*shareplugin.so
%{_datadir}/nemo-transferengine/plugins/*.qml
