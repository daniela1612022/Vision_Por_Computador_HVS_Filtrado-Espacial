#include <opencv2/opencv.hpp>
#include <iostream>

// cv::Mat resaltarColor(...): Define una función llamada resaltarColor
// (imganesInput , Hue - Color , r - rango , opcional - saturacion minima , valor minimo ) -> (imageOutput)
cv::Mat resaltarColor(const cv::Mat& img, int h, int r, int minSat = 50, int minVal = 50) {
    cv::Mat hsv, mask, gray, result;

    // Convertir la imagen de BGR a HSV
    // cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);: Convierte la imagen
    // de su formato original en BGR (Blue-Green-Red) a HSV (Hue-Saturation-Value).
    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);

    // Definir el rango de colores para resaltar
    int h1 = (h - r/2 + 360) % 360; // limite inferior (entre 0 y 359)
    int h2 = (h + r/2 + 360) % 360; // limite superior

    // Crear la máscara para el rango de colores
    // cv::inRange(...): Crea una máscara binaria donde los píxeles que están dentro del rango de color
    // especificado se ponen en blanco (valor 255) y los que están fuera de este rango se ponen en negro (valor 0).
    cv::inRange(hsv, cv::Scalar(h1, minSat, minVal), cv::Scalar(h2, 255, 255), mask);
    //  Hue, Saturation, y Value se especifican como cv::Scalar

    // Convertir las áreas no resaltadas a escala de grises
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY); // Convierte la imagen original de BGR a escala de grises
    cv::cvtColor(gray, result, cv::COLOR_GRAY2BGR); // Convierte la imagen en escala de grises de vuelta a BGR para que coincida con el formato de la imagen original

    // Combinar la imagen original con la parte resaltada
    // img.copyTo(result, mask);: Copia los píxeles de la imagen original a result, pero solo en los lugares donde la mask es blanca (valor 255)
    img.copyTo(result, mask);

    return result;
}

int main(int argc, char** argv) {
    // Cargar la imagen
    cv::Mat img = cv::imread("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/mes.jpg");
    if (img.empty()) {
        std::cout << "Error al cargar la imagen" << std::endl;
        return -1;
    }

    // Resaltar azul (Hue ~120)
    cv::Mat resaltarAzul = resaltarColor(img, 120, 20);

    // Resaltar verde (Hue ~60) con ajuste de rango
    cv::Mat resaltarVerde = resaltarColor(img, 60, 40, 40, 40);

    // Resaltar rojo (Hue ~0 y ~180)
    cv::Mat resaltarRojo1 = resaltarColor(img, 0, 20);
    cv::Mat resaltarRojo2 = resaltarColor(img, 180, 20);
    cv::Mat resaltarRojo = cv::max(resaltarRojo1, resaltarRojo2); // Combinar ambos

    // Mostrar las imágenes
    cv::imshow("Imagen Original", img);
    cv::imshow("Resaltar Azul", resaltarAzul);
    cv::imshow("Resaltar Verde", resaltarVerde);
    cv::imshow("Resaltar Rojo", resaltarRojo);

    // Guardar las imágenes resultantes
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/resaltar_azul.png", resaltarAzul);
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/resaltar_verde.png", resaltarVerde);
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/resaltar_rojo.png", resaltarRojo);

    cv::waitKey(0);
    return 0;
}
