extern "C" DATA_COLLECTION_SVC_PRODUCER_API bool data_collection_model_data_reporting_condition_is_equal_to_sans_context_ids(const data_collection_model_data_reporting_condition_t *first, const data_collection_model_data_reporting_condition_t *second)
{
    /* check pointers first */
    if (first == second) return true;
    const std::shared_ptr<DataReportingCondition > &obj2 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(second);
    if (!first) {
        if (!obj2) return true;
        return false;
    }
    const std::shared_ptr<DataReportingCondition > &obj1 = *reinterpret_cast<const std::shared_ptr<DataReportingCondition >*>(first);
    if (!second) {
        if (!obj1) return true;
        return false;
    }

    /* check what std::shared_ptr objects are pointing to */
    if (obj1 == obj2) return true;
    if (!obj1) return false;
    if (!obj2) return false;

    /* make some temp copies of the two objects without their contextIds */
    DataReportingCondition comp1(*obj1);
    comp1.clearContextIds();
    DataReportingCondition comp2(*obj2);
    comp2.clearContextIds();
    return comp1 == comp2;
}

