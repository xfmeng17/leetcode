class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minutes_ang = minutes * 6.0;
        double hour_ang = hour * 30.0 + minutes / 60.0 * 30.0;
        double ret = abs(minutes_ang - hour_ang);

        return ret >= 180 ? 360 - ret : ret;
    }
};