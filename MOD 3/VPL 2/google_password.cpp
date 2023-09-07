#include "google_password.hpp"

#include <iostream>
#include <string>


void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
  // TODO: Implemente este metodo
  /**
   * Lembre-se que as credenciais so podem ser inseridas com as seguintes
   * condicoes:
   * Condicao 1: A senha nao pode ter a seguencia '123456'.
   * Condicao 2: A senha nao pode ter mais do que 50 caracteres (no maximo 50).
   * Condicao 3: A senha nao pode ter menos do que 6 caracteres (no minimo 6).
   * Condicao 4: A senha nao pode ter caracteres em branco ' '.
   *
   * Exemplos de senhas invalidas:
   * 123456
   * test_123456
   * 123456_test
   * test_123456_test
   * senha test
   */
   
   if(checkPassword(password))
   {
        Usuario novoUsuario(login, password);
        m_passwords.insert(std :: pair<std::string, Usuario>(url, novoUsuario));
   }
}

void GooglePassword::remove(const std::string& url) {
  // TODO: Implemente este metodo
        m_passwords.erase(url);
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
  // TODO: Implemente este metodo
  /**
   * Caso a url nao seja encontrada, o metodo update deve ser ignorado, ou seja,
   * este metodo nao pode inserir novas credenciais. Alem disso, as informacoes
   * do usuario so podem ser atualizadas se a senha antiga for igual a senha
   * atual. Nao esqueca de verificar se o novo password tambem e valido.
   */
   std::map<std::string, Usuario>::iterator it;
   it = m_passwords.find(url);
   if(m_passwords.count(url) > 0)
   {
        if(it -> second.getPassword() == old_password && checkPassword(new_password))
        {
            it -> second.setPassword(new_password);
            it -> second.setLogin(login);
        }
   }
}

void GooglePassword::printPasswords() {
  // TODO: Implemente este metodo
  /**
   * Exemplo de saida:
   * www.site.com: login and password
   *
   */
   std :: cout << m_passwords.size() << std :: endl;
   for (std::map<std::string, Usuario>::iterator it = m_passwords.begin(); 
   it != m_passwords.end(); it++) 
    {
        std :: cout << it -> first << ": " << it -> second.getLogin() << " and " 
        << it -> second.getPassword()<< std :: endl;
    }
}

bool GooglePassword::checkPassword(const std::string& password) const {
  // TODO: Implemente este metodo
    if(password.length() < 6 ||password.length() > 50)
    {
        return false;
    }
    for(int i = 1; i < password.length(); i++)
    {
        if(password[i] == ' ' || password[i] == '6')
        {
            return false;
        }
    }
    return true;
  
}

