#include <opencv2/opencv.hpp>

int main() {
    // Leer la imagen de entrada
    cv::Mat inputImage = cv::imread("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/tutor.png", cv::IMREAD_GRAYSCALE);
    if (inputImage.empty()) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return -1;
    }

    // Aplicar binarización con un umbral
    cv::Mat binaryImage;
    // cv::THRESH_BINARY Los píxeles con un valor mayor o igual a 128 se establecen en 255 (blanco), y los demás en 0 (negro).
    cv::threshold(inputImage, binaryImage, 128, 255, cv::THRESH_BINARY);

    // Aplicar una erosión para adelgazar el texto
    // cv::MORPH_RECT crea un kernel de forma rectangular de 3x3 píxeles.
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::Mat erodedImage;
    cv::erode(binaryImage, erodedImage, kernel);

    // Guardar la imagen resultante
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/Binarizacion_Erosion.png", erodedImage);

    // Mostrar las imágenes
    cv::imshow("Original", inputImage);
    cv::imshow("Binarizada y Erosionada", erodedImage);
    cv::waitKey(0);

    return 0;
}
