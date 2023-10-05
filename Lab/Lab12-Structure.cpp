/*
    จงเขียนฟังก์ชันการตัดเกรดในแต่ละรายวิชาของนักเรียนจำนวน 3 คน โดยนักเรียนแต่ละคนจะมีข้อมูลดังต่อไปนี้
    ชื่อ, รหัสนักศึกษา, คะแนนในวิชาที่ 1, คะแนนในวิชาที่ 2, คะแนนในวิชาที่ 3, คะแนนในวิชาที่ 4, คะแนนในวิชาที่ 5
    แสดงได้ดังโครงสร้างข้อมูลต่อไปนี้

    struct Student {
        char Name[20] ;
        char ID[5] ;
        float ScoreSub1 ;
        float ScoreSub2 ;
        float ScoreSub3 ;
        float ScoreSub4 ;
        float ScoreSub5 ;
    } typedef S ;

    Test Case:
        Enter the details of 3 students :
        Student 1:
        Name: 
            John Doe
        ID: 
            101
        Scores in Subject 1: 
            77
        Scores in Subject 2: 
            64
        Scores in Subject 3: 
            66
        Scores in Subject 4: 
            54
        Scores in Subject 5: 
            56

        Student 2:
        Name: 
            Jane Smith
        ID: 
            102
        Scores in Subject 1: 
            43
        Scores in Subject 2: 
            70
        Scores in Subject 3: 
            76
        Scores in Subject 4: 
            77
        Scores in Subject 5: 
            80

        Student 3:
        Name: 
            Mark Johnson
        ID: 
            103
        Scores in Subject 1: 
            77
        Scores in Subject 2: 
            74
        Scores in Subject 3: 
            76
        Scores in Subject 4: 
            81
        Scores in Subject 5: 
            69

    Output:
    Student Details:
    Student 1:
    Name: John Doe
    ID: 101
    Scores: 77 64 66 54 56
    Grades: B+  C C+ D  D+
    Average Scores: 63.4

    Student 2:
    Name: Jane Smith
    ID: 102
    Scores: 43 70 76 77 80
    Grades:  F  B B+ B+  A
    Average Scores: 69.2

    Student 3:
    Name: Mark Johnson
    ID: 103
    Scores: 77 74 76 81 69
    Grades: B+  B B+  A C+
    Average Scores: 75.4
*/

#include <stdio.h>
#include <string.h>

struct Student {
        char Name[ 20 ] ;
        char ID[ 5 ] ;
        float ScoreSub1 ;
        float ScoreSub2 ;
        float ScoreSub3 ;
        float ScoreSub4 ;
        float ScoreSub5 ;
    } typedef s ;

void countgrades ( float score , char grades[] ) {

    // ตัดเกรดจากคะแนน
        if ( score >= 80 ) strcpy( grades, "A" ) ;
        else if ( score >= 75 && score <= 79 ) strcpy( grades, "B+" ) ;
        else if ( score >= 70 && score <= 74 ) strcpy( grades, "B" ) ;
        else if ( score >= 65 && score <= 69 ) strcpy( grades, "C+" ) ;
        else if ( score >= 60 && score <= 64 ) strcpy( grades, "C" ) ;
        else if ( score >= 55 && score <= 59 ) strcpy( grades, "D+" ) ;
        else if ( score >= 50 && score <= 54 ) strcpy( grades, "D" ) ;
        else strcpy( grades, "F" ) ;
    
} // end funtion countgrades

int main() {
    struct Student Students[ 3 ] ; // สร้างนักเรียนมา 3 คน
    printf ( "Enter the details of 3 students :\n" ) ;

    // ใส่ค่าลงในโครงสร้างข้อมูลของนักเรียน 3 คน
    for  ( int i = 0 ; i < 3 ; i++ ) {
        printf ( "Student %d:\n", i + 1 ) ;
        printf ( "Name:\n" ) ;
        gets( Students[ i ].Name ) ;

        printf ( "ID:\n" ) ;
        scanf ( "%s", &Students[ i ].ID ) ;

        printf ( "Scores in Subject 1: \n" ) ;
        scanf ( "%f", &Students[ i ].ScoreSub1 ) ;

        printf ( "Scores in Subject 2: \n" ) ;
        scanf ( "%f", &Students[ i ].ScoreSub2 ) ;

        printf ( "Scores in Subject 3: \n" ) ;
        scanf ( "%f", &Students[ i ].ScoreSub3 ) ;

        printf ( "Scores in Subject 4: \n" ) ;
        scanf ( "%f", &Students[ i ].ScoreSub4 ) ;

        printf ( "Scores in Subject 5: \n" ) ;
        scanf ( "%f", &Students[ i ].ScoreSub5 ) ;

        getchar();
    } // end for
    
    printf ( "Student Details\n" ) ;
    // แสดงข้อมูล
    for ( int i = 0 ; i < 3 ; i++ ) {
        printf ( "Student %d:\n", i + 1 ) ;
        printf ( "Name: %s\n", Students[ i ].Name ) ;
        printf ( "ID: %s\n", Students[ i ].ID ) ;
        printf ( "Scores: %.0f %.0f %.0f %.0f %.0f\n", Students[ i ].ScoreSub1 , Students[ i ].ScoreSub2 , Students[ i ].ScoreSub3 , Students[ i ].ScoreSub4 , Students[ i ].ScoreSub5 ) ;
        
        // คำนวนเกรด โดยเกรดมี 5 ช่อง และมี 3 คน
        char grades[ 5 ] [ 3 ] ;
        countgrades( Students[ i ].ScoreSub1, grades[ 0 ] ) ;
        countgrades( Students[ i ].ScoreSub2, grades[ 1 ] ) ;
        countgrades( Students[ i ].ScoreSub3, grades[ 2 ] ) ;
        countgrades( Students[ i ].ScoreSub4, grades[ 3 ] ) ;
        countgrades( Students[ i ].ScoreSub5, grades[ 4 ] ) ;
        printf ( "Grades:" ) ;
        for ( int j = 0 ; j < 5 ; j++ ) {
            printf( " %2s", grades[ j ] ) ;
        } // end for
        printf ( "\nAverage Score: %.1f\n", ( Students[ i ].ScoreSub1 + Students[ i ].ScoreSub2 + Students[ i ].ScoreSub3 + Students[ i ].ScoreSub4 + Students[ i ].ScoreSub5) / 5.00 ) ;  
    } // end for
    return 0 ;
} //end main function