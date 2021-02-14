#ifndef SUITES_H
#define SUITES_H

Suite *make_master_suite(void);
Suite *file_suite(void);
Suite *input_validation_suite(void);
Suite *card_validation_suite(void);

#endif /* SUITES_H */