// RobocupReferee.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "CleanUpReferee.h"

using namespace CleanUpReferee;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Form1 ^mform = gcnew Form1();
	Application::Run(mform);

	return 0;
}
