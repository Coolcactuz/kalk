#include "startup.h"

Startup::Startup() {

	QVBoxLayout* vertical_layout = new QVBoxLayout(this);
	
	QTextEdit* greetings = new QTextEdit("WELCOME TRUE IMBECILLONE", this);
	greetings->setReadOnly(true);

	vertical_layout->addWidget(greetings);
}
