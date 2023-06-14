// #include <functional>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <gyronimo/fields/IR3field_c1.hh>

// class Interpolator3D {
// public:
//     Interpolator3D(const std::vector<double>& s_values,
//                    const std::vector<double>& theta_values,
//                    const std::vector<double>& zeta_values,
//                    const std::function<double(const IR3& position)>& f)
//         : s_values(s_values), theta_values(theta_values), zeta_values(zeta_values) {
//         int s_size = s_values.size();
//         int theta_size = theta_values.size();
//         int zeta_size = zeta_values.size();
//         values.resize(s_size * theta_size * zeta_size);

//         for (int i = 0; i < s_size; ++i) {
//             for (int j = 0; j < theta_size; ++j) {
//                 for (int k = 0; k < zeta_size; ++k) {
//                     IR3 position({s_values[i], theta_values[j], zeta_values[k]});
//                     values[index(i, j, k)] = f(position);
//                 }
//             }
//         }
//     }

//     double interpolate(const IR3& position) const {
//         double s = position[IR3::u];
//         double theta = position[IR3::v];
//         double zeta = position[IR3::w];

//         int s_index = std::lower_bound(s_values.begin(), s_values.end(), s) - s_values.begin() - 1;
//         int theta_index = std::lower_bound(theta_values.begin(), theta_values.end(), theta) - theta_values.begin() - 1;
//         int zeta_index = std::lower_bound(zeta_values.begin(), zeta_values.end(), zeta) - zeta_values.begin() - 1;

//         double fs = (s - s_values[s_index]) / (s_values[s_index + 1] - s_values[s_index]);
//         double ftheta = (theta - theta_values[theta_index]) / (theta_values[theta_index + 1] - theta_values[theta_index]);
//         double fzeta = (zeta - zeta_values[zeta_index]) / (zeta_values[zeta_index + 1] - zeta_values[zeta_index]);

//         double result = 0.0;
//         for (int i = 0; i <= 1; ++i) {
//             for (int j = 0; j <= 1; ++j) {
//                 for (int k = 0; k <= 1; ++k) {
//                     double weight = ((i == 0) ? (1 - fs) : fs) * ((j == 0) ? (1 - ftheta) : ftheta) * ((k == 0) ? (1 - fzeta) : fzeta);
//                     result += weight * values[index(s_index + i, theta_index + j, zeta_index + k)];
//                 }
//             }
//         }
//         return result;
//     }

// private:
//     int index(int i, int j, int k) const {
//         return i * theta_values.size() * zeta_values.size() + j * zeta_values.size() + k;
//     }

//     std::vector<double> s_values, theta_values, zeta_values, values;
// };
