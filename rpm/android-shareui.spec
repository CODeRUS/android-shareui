Name:       android-shareui

%{!?qtc_qmake:%define qtc_qmake %qmake}
%{!?qtc_qmake5:%define qtc_qmake5 %qmake5}
%{!?qtc_make:%define qtc_make make}
%{?qtc_builddir:%define _builddir %qtc_builddir}
Summary:    Share to Android
Version:    0.1.2
Release:    1
Group:      Qt/Qt
License:    WTFPL
URL:        https://github.com/CODeRUS/android-shareui
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
%attr(4755, root, root) %{_bindir}/*
%{_libdir}/nemo-transferengine/plugins/*shareplugin.so
%{_datadir}/nemo-transferengine/plugins/*.qml
