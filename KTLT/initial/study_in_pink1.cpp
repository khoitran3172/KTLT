#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    int D = e1 * 3 + exp1 * 7; // Tính toán giá trị D dựa trên yêu cầu

    if (e1 >= 0 && e1 <= 3) {

        // Áp dụng các điều kiện và cập nhật EXP2 dựa trên E1
        switch (e1) {
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 += (29 + 45 + 75);
                break;
            default:
                break;
        }
        if (D % 2 == 0) {
            exp1 += ceil(D / 200.0);
        } else {
            exp1 -= ceil(D / 100.0);
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        // Xử lý trường hợp 2
        if (e1 >= 4 && e1 <= 19) {
            exp2 += ceil((e1 / 4.0) + 19);
        }
        else if (e1 >= 20 && e1 <= 49) {
            exp2 += ceil((e1 / 9.0) + 21);
        }
        else if (e1 >= 50 && e1 <= 65) {
            exp2 += ceil((e1 / 16.0) + 17);
        }
        else if (e1 >= 66 && e1 <= 79) {
            exp2 += ceil((e1 / 4.0) + 19);
            if (exp2 > 200) {
                exp2 += ceil((e1 / 9.0) + 21);
            }
        }
        else if (e1 >= 80 && e1 <= 99) {
            exp2 += ceil((e1 / 4.0) + 19);
            exp2 += ceil((e1 / 9.0) + 21);
            if (exp2 > 400) {
                exp2 += ceil((e1 / 16.0) + 17);
                exp2 = ceil( exp2 * 1.15);
            }
        }

        exp1 = exp1 - e1 ;
    } else {
        // Nếu E1 không nằm trong phạm vi đã cho
        return -99;
    }

    return exp1 + exp2;
}
int STask2(int x) {
    // Tìm số nguyên gần nhất với căn bậc hai của x
    int n = sqrt(x);

    // Kiểm tra xem n có phải là số chính phương hay không
    if (n * n == x) {
        return n;
    }

    // Nếu n không phải là số chính phương, tìm số chính phương gần nhất
    // bằng cách so sánh n^2 và (n + 1)^2 với x
    if (x - n * n < (n + 1) * (n + 1) - x) {
        return n * n;
    } else {
        return (n + 1) * (n + 1);
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // Xác định các biến cần thiết và khởi tạo giá trị ban đầu
    double P1 = 0, P2 = 0, P3 = 0; // Xác suất tìm thấy vali trên các con đường
    int S; // Số chính phương gần với giá trị EXP1 nhất
    int m = 0; // Biến lưu giá trị cho các sự kiện trên con đường 02
    int m1=0;
    bool continueEvents = true; // Biến kiểm tra xem có tiếp tục thực hiện các sự kiện trên con đường 02 hay không
    S = STask2(EXP1);
    // Xác định xác suất tìm thấy vali trên con đường 01
    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = ((double)EXP1 / S + 80) / 123;

    // Xác định các sự kiện trên con đường 02
    if(E2 % 2 != 0) m1= M1 * 0.5;
    while (continueEvents) {
        if (HP1 > 666) HP1 = 666;
        else if (HP1 < 0) HP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        else if (EXP1 < 0) EXP1 = 0;
        if (M1 > 3000) M1 = 3000;
        else if (M1 < 0) M1 = 0;

        if (HP1 < 200) {
            if (( m > m1) ||(M1 <=0))
            {
                continueEvents = false;
                HP1 = ceil(HP1 * 0.83); // Giảm HP 17%
                EXP1 = ceil(EXP1 * 1.17); // Tăng EXP 17%

                break;
            }
            HP1 =ceil(HP1 * 1.3); // Cộng thêm 30% HP hiện có
            M1 -= 150;
            m+=150;

        } else {
            if (( m > m1) ||(M1 <=0))
            {
                continueEvents = false;
                HP1 = ceil(HP1 * 0.83); // Giảm HP 17%
                EXP1 = ceil(EXP1 * 1.17); // Tăng EXP 17%

                break;
            }
            HP1 = ceil(HP1 * 1.1); // Cộng thêm 10% HP hiện có
            M1 -= 70;
            m += 70;


        }

        if (EXP1 < 400) {
            if (( m > m1) ||(M1 <=0))
            {
                continueEvents = false;
                HP1 = ceil(HP1 * 0.83); // Giảm HP 17%
                EXP1 = ceil(EXP1 * 1.17); // Tăng EXP 17%
                break;

            }
            EXP1 += ceil(EXP1 * 0.13); // Tăng EXP 13%
            M1 -= 200; // Trừ tiền thuê taxi
            m+= 200;


        } else {
            if (( m > m1) ||(M1 <=0))
            {
                continueEvents = false;
                HP1 = ceil(HP1 * 0.83); // Giảm HP 17%
                EXP1 = ceil(EXP1 * 1.17); // Tăng EXP 17%
                break;
            }
            EXP1 = ceil(EXP1 * 1.13); // Tăng EXP 13%
            M1 -= 120; // Trừ tiền thuê xe ngựa
            m+=120;
        }

        if (EXP1 < 300) {
            if (( m > m1) ||(M1 <=0))
            {

                continueEvents = false;
                HP1 = ceil(HP1 * 0.83); // Giảm HP 17%
                EXP1 = ceil(EXP1 * 1.17); // Tăng EXP 17%
                break;

            }
            EXP1 -= ceil(EXP1 * 0.1); // Giảm EXP 10%
            M1 -=  100;
            m+=100;

        } else {
            if (( m > m1) ||(M1 <=0))
            {
                continueEvents = false;
                HP1 = ceil(HP1 * 0.83); // Giảm HP 17%
                EXP1 = ceil(EXP1 * 1.17); // Tăng EXP 17%
                break;
            }
            EXP1 = ceil(EXP1 * 0.9); // Giảm EXP 10%
            M1 -=  120;
            m+=120;


        }

        // Kiểm tra điều kiện để tiếp tục hoặc dừng các sự kiện trên con đường 02
            if (E2 % 2 == 0) {

                continueEvents = false;
                HP1 = ceil(HP1 * 0.83); // Giảm HP 17%
                EXP1 = ceil(EXP1 * 1.17); // Tăng EXP 17%
            }


    }

    // Xác định xác suất tìm thấy vali trên con đường 02
//    cout<<"HP1 Up: "<<HP1<<" ;EXP1 Up: "<<EXP1<<" ;M1 Up: "<<M1<<endl;
    if (EXP1 >= S)
        P2 = 1;
    else
        P2 = ((double)EXP1 / S + 80) / 123;


    // Xác định xác suất tìm thấy vali trên con đường 03
    int probabilities[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2< 10) i = E2;
    else{
        i = (E2/10) + (E2%10);
        i = i%10;
    }
    P3 = probabilities[i] / 100.0; // Lấy giá trị xác suất tương ứng

    // Tính trung bình cộng của các xác suất trên các con đường
    double averageProbability = (P1 + P2 + P3) / 3;

    cout<<P1<<"      "<<P2<<"     "<<P3<<endl;
    // Xác định hành động cuối cùng dựa trên xác suất trung bình
    if (averageProbability == 1){
        EXP1 -= ceil(EXP1 * 0.25); // Giam EXP 25%
        traceLuggage(  HP1,   EXP1,   M1,  E2);
    }
    else if (averageProbability < 0.5) {
        HP1 -= ceil(HP1 * 0.15); // Giảm HP 15%
        EXP1 += ceil(EXP1 * 0.15); // Tăng EXP 15%
    } else {
        HP1 -= ceil(HP1 * 0.1); // Giảm HP 10%
        EXP1 += ceil(EXP1 * 0.2); // Tăng EXP 20%
    }

    // Đảm bảo giá trị HP1, EXP1, M1 không vượt quá hoặc nhỏ hơn giới hạn

    if (HP1 > 666) HP1 = 666;
    else if (HP1 < 0) HP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    else if (EXP1 < 0) EXP1 = 0;
    if (M1 > 3000) M1 = 3000;
    else if (M1 < 0) M1 = 0;

    return HP1 + EXP1 + M1;
}




int checkIJ(int num){
    int i=0;
    if (num <= 9) {
        i = num;
    }
        else{
            i = checkIJ((num/10)+(num%10));
        }
    return i;
    }
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // Khởi tạo ma trận 10x10 để biểu diễn bản đồ
    int map[10][10] = {0};

    // Tính điểm số của taxi tại từng vị trí trên bản đồ
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }


    // Khởi tạo ma trận để lưu điểm của Sherlock và Watson
    int scoreSherlockWatson[10][10] = {0};

    // Tính điểm số tối đa của Sherlock và Watson tại mỗi vị trí
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            // Tính điểm số tối đa từ đường chéo trái của taxi
            int maxLeftDiagonal = map[i][j];
            for (int k = i + 1, l = j - 1; k < 10 && l >= 0; ++k, --l) {
                maxLeftDiagonal = max(maxLeftDiagonal, map[k][l]);
            }

            // Tính điểm số tối đa từ đường chéo phải của taxi
            int maxRightDiagonal = map[i][j];
            for (int k = i + 1, l = j + 1; k < 10 && l < 10; ++k, ++l) {
                maxRightDiagonal = max(maxRightDiagonal, map[k][l]);
            }

            // Tính điểm số tối đa của Sherlock và Watson tại vị trí này
            scoreSherlockWatson[i][j] = max(maxLeftDiagonal, maxRightDiagonal);
        }
    }

    // Tìm vị trí gặp nhau của taxi, Sherlock và Watson
    int taxiRow = 0, taxiCol = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (map[i][j] > E3 * 2) {
                taxiRow ++;
            }
            if ( map[i][j] < -E3) {
                taxiCol++;
            }
        }
    }
    taxiRow = checkIJ(taxiRow);
    taxiCol= checkIJ(taxiCol);

    // Kiểm tra điểm số của taxi và Sherlock-Watson tại vị trí gặp nhau
    if (taxiRow != -1 && taxiCol != -1) {
        int taxiScore = map[taxiRow][taxiCol];
        int sherlockWatsonScore = scoreSherlockWatson[taxiRow][taxiCol];

        // Nếu giá trị tuyệt đối điểm số của taxi lớn hơn 2 người họ, họ không đuổi kịp
        if (abs(taxiScore) >   sherlockWatsonScore) {
            // Trừ HP và EXP tương ứng cho Sherlock và Watson
            HP1 = ceil(HP1 * 0.88); // Trừ 12% HP cho Sherlock
            EXP1 = ceil(EXP1 * 0.88); // Trừ 12% EXP cho Sherlock
            HP2 = ceil(HP2 * 0.88); // Trừ 12% HP cho Watson
            EXP2 = ceil(EXP2 * 0.88); // Trừ 12% EXP cho Watson
            return taxiScore ; // Trả về số điểm lớn hơn tương ứng
        } else {
            // Tăng HP và EXP tương ứng cho Sherlock và Watson
            HP1 = ceil(HP1 * 1.12); // Tăng 12% HP cho Sherlock
            EXP1 = ceil(EXP1 * 1.12); // Tăng 12% EXP cho Sherlock
            HP2 = ceil(HP2 * 1.12); // Tăng 12% HP cho Watson
            EXP2 = ceil(EXP2 * 1.12); // Tăng 12% EXP cho Watson
            return  sherlockWatsonScore; // Trả về số điểm lớn hơn tương ứng
        }
    } else {
        return -1; // Trả về -1 nếu không tìm thấy vị trí gặp nhau
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // Kiểm tra chiều dài của mật khẩu
    int len = strlen(s);
    if (len < 8) return -1; // Độ dài của mật khẩu quá ngắn
    if (len > 20) return -2; // Độ dài của mật khẩu quá dài

    // Kiểm tra sự tồn tại của ký tự đặc biệt
    bool hasSpecialChar = false;
    const char specialChars[] = "@#%$!";
    for (int i = 0; i < len; ++i) {
        if (strchr(specialChars, s[i]) != nullptr) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5; // Không chứa ký tự đặc biệt

    // Kiểm tra sự xuất hiện của chuỗi "se"
    const char *atPosition = strchr(email, '@'); // Tìm vị trí của ký tự '@' trong email
    if (atPosition == nullptr) return -99; // Không tìm thấy ký tự '@' trong email
    int seInEmailIndex = atPosition - email; // Xác định chỉ số của ký tự '@' trong email

    // Cấp phát bộ nhớ động cho con trỏ se
    char *se = new char[seInEmailIndex + 1];

    // Sao chép phần trước ký tự '@' của email vào se
    strncpy(se, email, seInEmailIndex);
    se[seInEmailIndex] = '\0'; // Kết thúc chuỗi

    // Kiểm tra sự xuất hiện của hơn 2 ký tự liên tiếp
    for (int i = 0; i < len - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // Xuất hiện hơn 2 ký tự liên tiếp
        }
    }

    // Kiểm tra sự xuất hiện của chuỗi se
    const char *seInPassword = strstr(s, se);
    if (seInPassword != nullptr) {
        return -(300 + (seInPassword - s)); // Xuất hiện chuỗi "se"
    }

    // Kiểm tra từng ký tự trong mật khẩu
    for (int i = 0; i < len; ++i) {
        // Kiểm tra ký tự có phải là chữ số, chữ cái thường, chữ cái in hoa, hoặc ký tự đặc biệt
        if (!((s[i] >= '0' && s[i] <= '9') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') ||
              strchr(specialChars, s[i]) != nullptr)) {
            return -(100 + i); // Ký tự không hợp lệ
        }
    }

    // Giải phóng bộ nhớ đã cấp phát
    delete[] se;

    // Mật khẩu hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;
    int maxLength = 0;
    const char* correctPassword = nullptr;

    // Tạo mảng để đếm số lần xuất hiện của mỗi mật khẩu
    int count[num_pwds];
    memset(count, 0, sizeof(count));

    // Tạo mảng để lưu độ dài của mỗi mật khẩu
    int length[num_pwds];
    memset(length, 0, sizeof(length));

    // Đếm số lần xuất hiện và tính độ dài của mỗi mật khẩu
    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int len = strlen(pwd);
        length[i] = len;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(pwd, arr_pwds[j]) == 0) {
                count[i]++;
            }
        }
    }

    // Tìm mật khẩu có số lần xuất hiện nhiều nhất và có độ dài dài nhất
    for (int i = 0; i < num_pwds; ++i) {
        if (count[i] > maxCount || (count[i] == maxCount && length[i] > maxLength)) {
            maxCount = count[i];
            maxLength = length[i];
            correctPassword = arr_pwds[i];
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu đúng trong mảng arr_pwds
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], correctPassword) == 0) {
            return i;
        }
    }

    // Trường hợp không tìm thấy
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
