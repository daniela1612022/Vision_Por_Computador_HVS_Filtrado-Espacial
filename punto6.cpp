#include <opencv2/opencv.hpp>

int main() {
    // Leer la imagen de entrada con ruido
    cv::Mat inputImage = cv::imread("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/lenanoise.png", cv::IMREAD_GRAYSCALE);
    if (inputImage.empty()) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return -1;
    }

    // Aplicar el filtro de mediana para eliminar el ruido
    cv::Mat outputImage;
    // cv::medianBlur(): Aplica un filtro de mediana a la imagen. Este filtro es muy eficaz para eliminar el ruido de tipo sal y pimienta.
    // el filtro de mediana es particularmente eficaz para preservar los bordes mientras elimina el ruido.( no lineal )
    cv::medianBlur(inputImage, outputImage, 5);

    // Guardar la imagen resultante
    cv::imwrite("/home/dani/Downloads/Vision_Por_Computador/Taller_Vision_2/Images/lena_filtered.png", outputImage);

    // Mostrar la imagen original y la imagen filtrada
    cv::imshow("Imagen con Ruido", inputImage);
    cv::imshow("Imagen Filtrada", outputImage);
    cv::waitKey(0);

    return 0;
}
