#include "stdafx.h"

using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;

//
// ����� �������� �� ���� ������ ��������������� ��������� �������
// ���������. �������������� �������� ���� ���������, ����� ��������
// ����� �������� �� ���� ������.
//
[assembly:AssemblyTitleAttribute("UT")];
[assembly:AssemblyDescriptionAttribute("")];
[assembly:AssemblyConfigurationAttribute("")];
[assembly:AssemblyCompanyAttribute("Microsoft")];
[assembly:AssemblyProductAttribute("UT")];
[assembly:AssemblyCopyrightAttribute("Copyright (c) Microsoft 2018")];
[assembly:AssemblyTrademarkAttribute("")];
[assembly:AssemblyCultureAttribute("")];

//
// �������� � ������ ������ ������� �� ��������� ������� ��������:
//
//      �������� ����� ������
//      �������������� ����� ������
//      ����� ����������
//      ��������
//
// ����� ������ ��� �������� ��� ������� ����� ���������� � ����� �������� �� ���������,
// ��������� "*", ��� �������� ����:

[assembly:AssemblyVersionAttribute("1.0.*")];
[assembly:ComVisible(false)];

