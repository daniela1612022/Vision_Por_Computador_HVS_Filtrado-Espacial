#include <opencv2/opencv.hpp>

int main() {
    // Leer la imagen de entrada
    cv::Mat inputImage = cv::imread("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/ave2.png", cv::IMREAD_GRAYSCALE);
    if (inputImage.empty()) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return -1;
    }

    // Aplicar binarización con un umbral
    cv::Mat binaryImage;
    cv::threshold(inputImage, binaryImage, 128, 255, cv::THRESH_BINARY);

    // Definir el kernel para la operación morfológica
    // Se define un kernel de tamaño 7x7 con forma rectangular (cv::MORPH_RECT).
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));

    // Aplicar apertura para eliminar el ruido
    cv::Mat cleanedImage;
    // Se aplica la operación de apertura (cv::MORPH_OPEN) a la imagen binaria utilizando el kernel definido.
    // es una combinación de erosión seguida de dilatación, lo que ayuda a eliminar pequeños puntos de ruido (objetos blancos)
    // en la imagen mientras se preservan las formas más grandes.
    cv::morphologyEx(binaryImage, cleanedImage, cv::MORPH_OPEN, kernel);

    // Guardar la imagen resultante
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/Ave_Apertura.png", cleanedImage);

    // Mostrar las imágenes
    cv::imshow("Original", inputImage);
    cv::imshow("Binarizada y Limpiada", cleanedImage);
    cv::waitKey(0);

    return 0;
}
