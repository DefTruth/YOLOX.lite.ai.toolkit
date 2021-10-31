//
// Created by DefTruth on 2021/7/20.
//

#include "lite/lite.h"

static void test_default()
{
  std::string onnx_path = "../hub/onnx/cv/yolox_s.onnx";
  std::string test_img_path = "../resources/4.jpg";
  std::string save_img_path = "../logs/4.jpg";

  // 1. Test Default Engine ONNXRuntime
  auto *yolox = new lite::cv::detection::YoloX(onnx_path); // default

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolox->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "Default Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete yolox;

}

static void test_onnxruntime()
{
#ifdef ENABLE_ONNXRUNTIME
  std::string onnx_path = "../hub/onnx/cv/yolox_s.onnx";
  std::string test_img_path = "../resources/6.jpg";
  std::string save_img_path = "../logs/6.jpg";

  // 2. Test Specific Engine ONNXRuntime
  auto *yolox = new lite::onnxruntime::cv::detection::YoloX(onnx_path);

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolox->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "ONNXRuntime Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete yolox;
#endif
}

static void test_mnn()
{
#ifdef ENABLE_MNN
  std::string mnn_path = "../hub/mnn/cv/yolox_s.mnn";
  std::string test_img_path = "../resources/7.jpg";
  std::string save_img_path = "../logs/7.jpg";

  // 3. Test Specific Engine MNN
  auto *yolox = new lite::mnn::cv::detection::YoloX(mnn_path);

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolox->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "MNN Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete yolox;
#endif
}

static void test_ncnn()
{
#ifdef ENABLE_NCNN
  std::string param_path = "../hub/ncnn/cv/yolox_s.opt.param";
  std::string bin_path = "../hub/ncnn/cv/yolox_s.opt.bin";
  std::string test_img_path = "../resources/5.jpg";
  std::string save_img_path = "../logs/5.jpg";

  // 4. Test Specific Engine NCNN
  auto *yolox = new lite::ncnn::cv::detection::YoloX(param_path, bin_path);

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolox->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "NCNN Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete yolox;
#endif
}

static void test_tnn()
{
#ifdef ENABLE_TNN
  std::string proto_path = "../hub/tnn/cv/yolox_s.opt.tnnproto";
  std::string model_path = "../hub/tnn/cv/yolox_s.opt.tnnmodel";
  std::string test_img_path = "../resources/9.jpg";
  std::string save_img_path = "../logs/9.jpg";

  // 5. Test Specific Engine TNN
  auto *yolox = new lite::tnn::cv::detection::YoloX(proto_path, model_path);

  std::vector<lite::types::Boxf> detected_boxes;
  cv::Mat img_bgr = cv::imread(test_img_path);
  yolox->detect(img_bgr, detected_boxes);

  lite::utils::draw_boxes_inplace(img_bgr, detected_boxes);

  cv::imwrite(save_img_path, img_bgr);

  std::cout << "TNN Version Detected Boxes Num: " << detected_boxes.size() << std::endl;

  delete yolox;
#endif
}

static void test_lite()
{
  test_default();
  test_onnxruntime();
  test_mnn();
  test_ncnn();
  test_tnn();
}

int main(__unused int argc, __unused char *argv[])
{
  test_lite();
  return 0;
}
