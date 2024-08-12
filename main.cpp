/******************************************************************************

Actividad 3 proyecto final 
*******************************************************************************/
#include <iostream>
#include <string>

//Función para obtener la primera vocal interna de una cadena de texto
char obtenerPrimeraVocalInterna(const std::string& str) { 
    for (size_t i = 1; i < str.length(); ++i) {
        char c = str[i];
        if (c == 'A' || c == 'E' || c == 'I' ||c == 'O' || c == 'U')
        return c; 
        
    }
    return 'X'; // Si no se encuentra nunguna vocal interna, se usa una X 
}
    
//Función principal para calcular RFC
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string& fechaNacimiento){
    std::string rfc;
    
    //Se obtiene la letra inicial y la primera vocal interna del apellido paterno 
    char letraInicial = apellidoPaterno[0];
    char primeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
    
    //Se obtiene la inicial del apellido materno o se usa una X si no lo tiene 
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
    
    //Se obtiene la inicial del primer nombre de lo contrario se usa una X si no hay 
    char inicialNombre = nombre[0];
    
    //Se obtienen los dos últimos dígitos del año de fechaNacimiento
    std::string año = fechaNacimiento.substr(2,2);
    
    //Se obtiene el mes y dia denacimiento 
    std::string mes = fechaNacimiento.substr(5,2);
    std::string dia = fechaNacimiento.substr(8.2);
    
    //Se construye el RFC 
    rfc = letraInicial;
    rfc += primeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;
    rfc += año;
    rfc += mes;
    rfc += dia;
    return rfc;
}

int main() {
   std::string nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento;
   
   std::cout << "Introduce el nombre: ";
   std::getline(std::cin, nombre);
   
   std::cout << "Introduce el apellido paterno: ";
   std::getline(std::cin, apellidoPaterno);
   
   std::cout << "Introduce el apellido materno(si no tiene, presione Enter): ";
   std::getline(std::cin, apellidoMaterno);   
   
   std::cout << "Introduce la fecha de nacimiento (YYY-MM-DD): ";
   std::getline(std::cin, fechaNacimiento);
   
   std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
   std::cout << "RFC: " << rfc << std::endl;
   
   return 0;
}