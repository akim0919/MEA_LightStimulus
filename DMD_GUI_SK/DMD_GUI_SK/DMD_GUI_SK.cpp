#include "DMD_GUI_SK.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	DMDGUISK::DMD_GUI_SK form;	// DMDGUISK - The name of the project, DMD_GUI_SK - .h, .cpp The name of the file
	Application::Run(% form);
}
