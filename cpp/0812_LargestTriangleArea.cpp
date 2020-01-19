class Solution {
public:
  double largestTriangleArea(vector<vector<int>> &points) {
    // return func1(points);
    return func2(points);
  }

  // ** func1 Time(N^3)
  // ** straight forward with Heron's formula
  // ** Wrong Answer, I think it exists some mathematical precision problem.
  /**********
  Heron's formula:
  A = sqrt ( s * (s - a) * (s - b) * (s - c) ) and s = (a + b + c) / 2
  **********/
  double func1(vector<vector<int>> &points) {
    double res = 0.0;
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        for (int k = j + 1; k < points.size(); k++) {
          double a = sqrt(pow((points[i][0] - points[j][0]), 2) +
                          pow((points[i][1] - points[j][1]), 2));
          double b = sqrt(pow((points[i][0] - points[k][0]), 2) +
                          pow((points[i][1] - points[k][1]), 2));
          double c = sqrt(pow((points[j][0] - points[k][0]), 2) +
                          pow((points[j][1] - points[k][1]), 2));
          double s = (a + b + c) / 2.0;
          double area = sqrt(s * (s - a) * (s - b) * (s - c));
          res = max(area, res);
        }
      }
    }
    return res;
  }

  // ** func2 Time(N^3)
  /********** QingJiuZhao's formula:
  A = sqrt ( (1.0/4.0) * [ (a2 * c2 - (a2 + c2 - b2)/2.0 * (a2 + c2 - b2)/2.0 ]
  ) and a2 = a * a, same b2 ,c2.
  **********/
  double func2(vector<vector<int>> &points) {
    double res = 0.0;
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        for (int k = j + 1; k < points.size(); k++) {
          double a = pow((points[i][0] - points[j][0]), 2) +
                     pow((points[i][1] - points[j][1]), 2);
          double b = pow((points[i][0] - points[k][0]), 2) +
                     pow((points[i][1] - points[k][1]), 2);
          double c = pow((points[j][0] - points[k][0]), 2) +
                     pow((points[j][1] - points[k][1]), 2);
          double A = max(max(a, b), max(b, c));
          double C = min(min(a, b), min(b, c));
          double B = 0.0;
          if (A == b) {
            B = max(a, c);
          } else if (C == b) {
            B = min(a, c);
          } else {
            B = b;
          }
          double area =
              sqrt((1.0 / 4.0) * ((A * C) - pow((A + C - B) / 2.0, 2)));
          res = max(area, res);
        }
      }
    }
    return res;
  }

  // ** func3 Time(N^3)
  /********** coordinate geometry formula:
  area = |Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By)| / 2
  **********/
  double func3(vector<vector<int>> &points) {
    double res = 0.0;
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        for (int k = j + 1; k < points.size(); k++) {
          double a = points[i][0] * (points[j][1] - points[k][1]);
          double b = points[j][0] * (points[k][1] - points[i][1]);
          double c = points[k][0] * (points[i][1] - points[j][1]);
          double area = abs((a + b + c) / 2.0);
          res = max(res, area);
        }
      }
    }
    return res;
  }
};
