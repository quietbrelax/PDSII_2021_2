#include "usuario.hpp"

Usuario::Usuario(const std::string& login, const std::string& password) {
  // TODO: Implemente este metodo
  this -> _login = login;
  this -> _password = password;
}

std::string Usuario::getLogin() const {
  // TODO: Implemente este metodo
  return _login;
}

std::string Usuario::getPassword() const {
  // TODO: Implemente este metodo
  return _password;
}

void Usuario::setPassword(const std::string& password) {
  // TODO: Implemente este metodo
  this -> _password = password;
}

void Usuario::setLogin(const std::string& login) {
  // TODO: Implemente este metodo
  this -> _login = login;
}