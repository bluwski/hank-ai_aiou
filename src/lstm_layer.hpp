#pragma once

#include "activations.hpp"
#include "layer.hpp"
#include "network.hpp"
#define USET

#ifdef __cplusplus
extern "C" {
#endif
layer make_lstm_layer(int batch, int inputs, int outputs, int steps, int batch_normalize);

void forward_lstm_layer(layer l, network_state state);
void backward_lstm_layer(layer l, network_state state);
void update_lstm_layer(layer l, int batch, float learning_rate, float momentum, float decay);

#ifdef GPU
void forward_lstm_layer_gpu(layer l, network_state state);
void backward_lstm_layer_gpu(layer l, network_state state);
void update_lstm_layer_gpu(layer l, int batch, float learning_rate, float momentum, float decay, float loss_scale);
#endif

#ifdef __cplusplus
}
#endif
