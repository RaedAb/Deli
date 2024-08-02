#include "../include/Receipt.hpp"

/**
 * @brief Read and process image
 *
 * Reads the image from image and converts to black and white
 *
 * @param imagePath path to the receipt image
 */
void preprocessImage(const std::string &imagePath)
{
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_GRAYSCALE);
    cv::threshold(image, image, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    cv::imwrite("preprocessed_receipt.png", image);
}