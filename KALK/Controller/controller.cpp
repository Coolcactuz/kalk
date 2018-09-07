#include "controller.h"

controller::controller(): cv(new controller_view()), tipo_corrente(0), from_gui(""),
                          conv_complesso(0), conv_raz(0.0){
  QObject::connect(cv, SIGNAL(inviaTipo(int)), this, SLOT(defineTC(int)));
  QObject::connect(cv, SIGNAL(inviaStringa(QString)), this, SLOT(data_GUI_to_controller(QString)));

  QObject::connect(cv, SIGNAL(SOComplesso(int)), this, SLOT(socomplesso_logic(int)));
  QObject::connect(cv, SIGNAL(SORaz(int)), this, SLOT(soraz_logic(int)));

  QObject::connect(cv, SIGNAL(controller_view_inviaVolt(double)), this, SLOT(circuito_cambia_volt(double)));
  QObject::connect(cv, SIGNAL(controller_view_inviaFreq(double)), this, SLOT(circuito_cambia_freq(double)));


  QObject::connect(this, SIGNAL(data_controller_to_GUI(QString)), cv, SIGNAL(inviaResult(QString)));

  QObject::connect(this, SIGNAL(CtV_exception(QString, bool)), cv, SIGNAL(pass_exception(QString, bool)));

  QObject::connect(cv, SIGNAL(emergenza3()), this, SLOT(gestisci_emergenza()));
}

void controller::check_string(std::string s) const{

  if(s == ""){
    throw syntax_exception("stringa vuota");
  }

  std::size_t found = s.find_first_not_of(".+*%/-^(),<abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890");
  if(found != std::string::npos){
    throw syntax_exception("La stringa contiene caratteri speciali");
  }
  if(s.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") == std::string::npos){
    throw syntax_exception("La stringa contiene solo operatori");
  }
}

void controller::gestisci_emergenza(){
  if(cv){
    delete cv;
  }
  if(conv_complesso){
    delete conv_complesso;
  }

  std::exit(1);
}

controller::~controller(){

  if(cv){
    delete cv;
  }

  if(conv_complesso){
    delete conv_complesso;
  }

}

void controller::defineTC(int tc){
  tipo_corrente = tc;
}

void controller::data_GUI_to_controller(QString s){
  from_gui = s;
  Dato* tmp = 0;
  QString qstmp = "";

  try{
    std::string stringa_da_controllare = from_gui.toUtf8().constData();
    check_string(stringa_da_controllare);
    switch (tipo_corrente){
      case 1:
      {
        tmp = new Raz(); //oggetto fittizio per il parser
        parser<Raz> pr(from_gui.toUtf8().constData(), tmp);
        Dato* result = parser<Raz>::resolve(pr.getStart());
        conv_raz = double(*(static_cast<Raz*> (result)));
        qstmp = QString(result->toString().c_str());
      }
      break;
      case 2:
      {
        tmp = new C_cartesiano();  //oggetto fittizio per il parser
        parser<Complesso> pc(from_gui.toUtf8().constData(), tmp);
        Dato* result = parser<Complesso>::resolve(pc.getStart());
        conv_complesso = (static_cast<Complesso*> (result))->converti();
        qstmp = QString(result->toString().c_str());
      }
      break;
      // case 3:
      // {
      //   tmp = new tupla(); //oggetto fittizio per il parser
      //   parser<tupla> pt(from_gui.toUtf8().constData(), tmp);
      //   Dato* result = parser<tupla>::resolve(pt.getStart());
      //   qstmp = QString(result->toString().c_str());
      // }
      // break;
      default:
      {
        tmp = new Condensatore(); //oggetto fittizio per il parser
        parser<Componente> pcomponente(from_gui.toUtf8().constData(), tmp);
        Dato* result = parser<Componente>::resolve(pcomponente.getStart());
        qstmp = QString(result->toString().c_str());
      }
      break;
    }

    delete tmp;

    emit data_controller_to_GUI(qstmp);
  }
  catch(const syntax_exception & se){
    if(tmp)
      delete tmp;
    emit CtV_exception(QString(se.getErrorMessage().c_str()), true);
  }
  catch(const logic_exception & le){
    if(tmp)
      delete tmp;
    emit CtV_exception(QString(le.getErrorMessage().c_str()), false);
  }
}

void controller::soraz_logic(int i){
  Dato* fittizio = new Raz();
  parser<Raz> pr(from_gui.toUtf8().constData(), fittizio);
  delete fittizio;
  Dato* dato_tmp = parser<Raz>::resolve(pr.getStart());
  Raz* result = static_cast<Raz*>(dato_tmp);

  try{
    switch (i){
      case -6:
        emit data_controller_to_GUI(QString(std::to_string(result->radice_quadrata()).c_str()));
      break;
      case -7:
        {
          Raz* tmp = result->reciproco();
          Raz raz_obj = *tmp;
          delete tmp;
          emit data_controller_to_GUI(QString(raz_obj.toString().c_str()));
        }
      break;
      default:
        emit data_controller_to_GUI(QString(std::to_string(conv_raz).c_str()));
      break;
    }
  }
  catch(const syntax_exception & se){
    emit CtV_exception(QString(se.getErrorMessage().c_str()), true);
  }
  catch(const logic_exception & le){
    emit CtV_exception(QString(le.getErrorMessage().c_str()), false);
  }
}

void controller::socomplesso_logic(int i){
  Dato* fittizio = new C_cartesiano();
  parser<Complesso> pr(from_gui.toUtf8().constData(), fittizio);
  delete fittizio;
  Dato* dato_tmp = parser<Complesso>::resolve(pr.getStart());
  Complesso* result = static_cast<Complesso*>(dato_tmp);
  QString qstmp = "";

  try{
    switch (i){
      case -4:
        qstmp = QString(conv_complesso->toString().c_str());
        emit data_controller_to_GUI(qstmp);
      break;
      default:
      {
        Complesso* result_coniugato = result->coniugato();
        qstmp = result_coniugato->toString().c_str();
        delete result_coniugato;
        emit data_controller_to_GUI(qstmp);
      }
      break;
    }
  }
  catch(const syntax_exception & se){
    emit CtV_exception(QString(se.getErrorMessage().c_str()), true);
  }
  catch(const logic_exception & le){
    emit CtV_exception(QString(le.getErrorMessage().c_str()), false);
  }
}

void controller::circuito_cambia_volt(double d){
 try{
   Componente::setVolt(d);
   std::cout << Componente::getVolt() << std::endl;
 }
 catch(const syntax_exception & se){
    std::cout << Componente::getVolt() << std::endl;
    emit CtV_exception(QString(se.getErrorMessage().c_str()), true);
 }
}

void controller::circuito_cambia_freq(double d){
 try{
  Componente::setFreq(d);
 }
 catch(const syntax_exception & se){
    emit CtV_exception(QString(se.getErrorMessage().c_str()), true);
 }
}
