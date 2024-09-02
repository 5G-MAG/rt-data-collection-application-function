extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_rule_is_equal_to_sans_context_ids(const data_collection_model_data_reporting_rule_t *first, const data_collection_model_data_reporting_rule_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReportingRule > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReportingRule > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingRule >*>(first);
    if (!second) {
        if (!obj1) return true;
        return false;
    }

    /* check what std::shared_ptr objects are pointing to */
    if (obj1 == obj2) return true;
    if (!obj1) return false;
    if (!obj2) return false;

    /* make some temp copies of the two objects without their contextIds */
    DataReportingRule comp1(*obj1);
    comp1.clearContextIds();
    DataReportingRule comp2(*obj2);
    comp2.clearContextIds();
    return comp1 == comp2;
}

