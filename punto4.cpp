#include <opencv2/opencv.hpp>

int main() {
    // Leer la imagen de entrada
    cv::Mat inputImage = cv::imread("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/ave.jpg", cv::IMREAD_GRAYSCALE);
    if (inputImage.empty()) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return -1;
    }

    // Aplicar binarización con un umbral
    cv::Mat binaryImage;
    cv::threshold(inputImage, binaryImage, 128, 255, cv::THRESH_BINARY);

    // Definir el kernel para la operación morfológica
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));

    // Aplicar cierre para eliminar los agujeros dentro de la figura
    cv::Mat closedImage;
    // La operación de cierre primero dilata la imagen, lo que cierra pequeños agujeros en las áreas blancas,
    // y luego aplica erosión para restaurar el tamaño original de las áreas blancas.
    cv::morphologyEx(binaryImage, closedImage, cv::MORPH_CLOSE, kernel);

    // Guardar la imagen resultante
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/Ave_Cierre.png", closedImage);

    // Mostrar las imágenes
    cv::imshow("Original", inputImage);
    cv::imshow("Binarizada y Cerrada", closedImage);
    cv::waitKey(0);

    return 0;
}
