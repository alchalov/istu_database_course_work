SELECT FamilyName, BornYear, JoinYear, Sex, ClassName, ClassTeacher, TeachersPhone FROM students LEFT JOIN classes ON students.IdClass = classes.IdClass WHERE classes.IdSchool=4