
CuString* cardValidation = "400000000000;499999999999;VISA;\n50000000;59999999;MASTERCARD;\n67000000;67999999;MAESTRO;";

void TestShouldLoadValidationFile(CuTest* tc){
    CuString* fileContents = loadValidationFile();

    CuAssertStrEquals(tc, cardValidation->buffer, fileContents->buffer);
}

CuSuite* CuGetSuite(void)
{
	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestShouldLoadValidationFile);

	return suite;
}