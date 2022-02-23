/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _EI_CLASSIFIER_ANOMALY_CLUSTERS_H_
#define _EI_CLASSIFIER_ANOMALY_CLUSTERS_H_

#include "edge-impulse-sdk/anomaly/anomaly.h"

// (before - mean) / scale
const float ei_classifier_anom_scale[EI_CLASSIFIER_ANOM_AXIS_SIZE] = { 2.902045958987966, 3.1971906219370863, 1.2265900123641436 };
const float ei_classifier_anom_mean[EI_CLASSIFIER_ANOM_AXIS_SIZE] = { 2.475023831236713, 2.6088124246027204, 0.6575220109813921 };

const ei_classifier_anom_cluster_t ei_classifier_anom_clusters[EI_CLASSIFIER_ANOM_CLUSTER_COUNT] = { { { 0.83899986743927, 0.8025673031806946, 0.14049366116523743 }, 0.9371424523744627 }
, { { -0.43391719460487366, -0.434204638004303, -0.5015766024589539 }, 0.2692631638112799 }
, { { -0.11478263884782791, -0.1613825410604477, 0.28293073177337646 }, 0.3214727296600392 }
, { { -0.8484280705451965, -0.8133829236030579, -0.5356177091598511 }, 0.25065140077018105 }
, { { -0.2633891999721527, -0.2548810541629791, -0.5050824880599976 }, 0.277609844164188 }
, { { -0.02223583310842514, -0.07526232302188873, 0.7303707599639893 }, 0.36886581975709504 }
, { { 3.082824230194092, 2.9403836727142334, -0.4210403561592102 }, 0.7331952638848569 }
, { { 0.1564636528491974, 0.12483033537864685, 0.020408328622579575 }, 0.4094783351830038 }
, { { 0.6128610372543335, 0.5760907530784607, -0.2285740226507187 }, 0.42359796891209867 }
, { { -0.49113011360168457, -0.4822240471839905, 1.5136187076568604 }, 0.4006782667535379 }
, { { 0.11115691810846329, 0.12200310826301575, 1.7785999774932861 }, 1.0654355811788025 }
, { { 0.039197444915771484, 0.007769806310534477, -0.4674590826034546 }, 0.31658715037316704 }
, { { -0.30905020236968994, -0.2895829379558563, 4.936167240142822 }, 0.6532632275600622 }
, { { 1.4148224592208862, 1.4214658737182617, -0.2644645571708679 }, 0.47412704108320336 }
, { { -0.1358228623867035, -0.17949244379997253, 1.2902404069900513 }, 0.3902986367771864 }
, { { 2.6966712474823, 2.498335361480713, 0.21515978872776031 }, 0.6656658520332894 }
, { { 2.1892025470733643, 2.5552005767822266, -0.3997782766819 }, 0.38191855506651123 }
, { { 2.4799671173095703, 2.9782443046569824, -0.47436603903770447 }, 0.29100542367177523 }
, { { 0.3047245144844055, 0.2789483368396759, -0.43158599734306335 }, 0.34310191215390035 }
, { { -0.31814801692962646, -0.32611122727394104, 2.201617479324341 }, 0.448144215733126 }
, { { 1.939394235610962, 2.3038852214813232, -0.04412435367703438 }, 0.521650336120765 }
, { { -0.3958195447921753, -0.42489179968833923, 0.890632688999176 }, 0.3320398654860707 }
, { { -0.34238138794898987, -0.38652747869491577, -0.13867387175559998 }, 0.35282054141763475 }
, { { 2.6603055000305176, 2.526960849761963, 1.1465336084365845 }, 0.9120512118033713 }
, { { 3.3950252532958984, 3.4812817573547363, -0.4841405749320984 }, 0.8527649697784858 }
, { { -0.22909493744373322, -0.27734488248825073, 6.101161003112793 }, 0.6162511937458194 }
, { { -0.46638673543930054, -0.49719810485839844, 0.3677430748939514 }, 0.31920106147046845 }
, { { -0.31950950622558594, -0.3205442726612091, 2.8616485595703125 }, 0.5996431876445376 }
, { { -0.38585489988327026, -0.39332371950149536, 3.9820945262908936 }, 0.4845075447477559 }
, { { 1.5523451566696167, 1.376094102859497, 4.232600212097168 }, 0.8103168800864807 }
};

#endif // _EI_CLASSIFIER_ANOMALY_CLUSTERS_H_