#include "startup.h"

Startup::Startup() {	//setup of the startup view

	/* startup view dimensions and positioning */
	QWidget::showMaximized();


	/* vertical external layout */
	QVBoxLayout* external_layout = new QVBoxLayout(this);


	/* headline text */
	QFont hf("Arial", 70, QFont::Bold);
	QLabel* greetings = new QLabel("KALK", this);
	greetings->setAlignment(Qt::AlignCenter);
	greetings->setFont(hf);

	/* first internal horizontal layout */
	QHBoxLayout* fihlayout = new QHBoxLayout(this);
	fihlayout->addWidget(greetings);

	/* second horizontal internal layout */
	QHBoxLayout* sihlayout = new QHBoxLayout(this);

	/* create the selection buttons */
	QPushButton* num_t = new QPushButton("NUMERICAL TYPES", this);
	num_t->setMinimumSize(200, 200);
	//num_t->setMaximumSize(600, 600);

	QPushButton* circuits = new QPushButton("CIRCUITS", this);
	circuits->setMinimumSize(200, 200);


	QPushButton* sim = new QPushButton("SYMPHONIES", this);
	sim->setMinimumSize(200, 200);


	/* added buttons to horizontal layout */
	sihlayout->addWidget(num_t);
	sihlayout->addWidget(circuits);
	sihlayout->addWidget(sim);

	/* added horizontal layouts to vertical layout */
	external_layout->addLayout(fihlayout);
	external_layout->addLayout(sihlayout);

}
