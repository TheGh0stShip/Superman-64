typedef float f32;

extern f32 func_800BE410(f32 angle);
extern f32 func_800CFC60(f32 angle);

void func_800CDDD0(f32 matrix[4][4], f32 roll, f32 pitch, f32 yaw,
                   f32 scale, f32 x, f32 y, f32 z) {
    static f32 degrees_to_radians = 3.1415926 / 180.0;
    f32 sin_roll;
    f32 sin_pitch;
    f32 sin_yaw;
    f32 cos_roll;
    f32 cos_pitch;
    f32 cos_yaw;

    roll *= degrees_to_radians;
    pitch *= degrees_to_radians;
    yaw *= degrees_to_radians;
    sin_roll = func_800BE410(roll);
    cos_roll = func_800CFC60(roll);
    sin_pitch = func_800BE410(pitch);
    cos_pitch = func_800CFC60(pitch);
    sin_yaw = func_800BE410(yaw);
    cos_yaw = func_800CFC60(yaw);

    matrix[0][0] = (cos_pitch * cos_yaw) * scale;
    matrix[0][1] = (cos_pitch * sin_yaw) * scale;
    matrix[0][2] = (-sin_pitch) * scale;
    matrix[0][3] = 0.0;

    matrix[1][0] = (sin_roll * sin_pitch * cos_yaw - cos_roll * sin_yaw) * scale;
    matrix[1][1] = (sin_roll * sin_pitch * sin_yaw + cos_roll * cos_yaw) * scale;
    matrix[1][2] = (sin_roll * cos_pitch) * scale;
    matrix[1][3] = 0.0;

    matrix[2][0] = (cos_roll * sin_pitch * cos_yaw + sin_roll * sin_yaw) * scale;
    matrix[2][1] = (cos_roll * sin_pitch * sin_yaw - sin_roll * cos_yaw) * scale;
    matrix[2][2] = (cos_roll * cos_pitch) * scale;
    matrix[2][3] = 0.0;

    matrix[3][0] = x;
    matrix[3][1] = y;
    matrix[3][2] = z;
    matrix[3][3] = 1.0;
}
