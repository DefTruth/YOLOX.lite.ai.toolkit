//
// Created by DefTruth on 2021/10/7.
//

#ifndef LITE_AI_TOOLKIT_NCNN_CORE_NCNN_CORE_H
#define LITE_AI_TOOLKIT_NCNN_CORE_NCNN_CORE_H

#include "ncnn_config.h"
#include "ncnn_handler.h"
#include "ncnn_types.h"
#include "ncnn_custom.h"

namespace ncnncv
{
  class LITE_EXPORTS NCNNNanoDet;                                // [0] * reference: https://github.com/RangiLyu/nanodet
  class LITE_EXPORTS NCNNNanoDetEfficientNetLite;                // [1] * reference: https://github.com/RangiLyu/nanodet
  class LITE_EXPORTS NCNNNanoDetDepreciated;                     // [2] * reference: https://github.com/RangiLyu/nanodet
  class LITE_EXPORTS NCNNNanoDetEfficientNetLiteDepreciated;     // [3] * reference: https://github.com/RangiLyu/nanodet
  class LITE_EXPORTS NCNNRobustVideoMatting;                     // [4] * reference: https://github.com/PeterL1n/RobustVideoMatting
  class LITE_EXPORTS NCNNYoloX;                                  // [5] * reference: https://github.com/Megvii-BaseDetection/YOLOX
}

namespace ncnncv
{
  using ncnncore::BasicNCNNHandler;
}

namespace ncnnnlp
{
  using ncnncore::BasicNCNNHandler;
}

namespace ncnnasr
{
  using ncnncore::BasicNCNNHandler;
}

#endif //LITE_AI_TOOLKIT_NCNN_CORE_NCNN_CORE_H
