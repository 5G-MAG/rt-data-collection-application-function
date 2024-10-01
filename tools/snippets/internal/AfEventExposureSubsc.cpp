
#include "openapi/model/AfEventExposureNotif.h"

/** Get the JSON for an AfEventExposureSubsc response which includes the given notifications
 *
 * If af_events_notifications is NULL then there are no event notifications to include and the JSON object will leave this part of
 * the response empty.
 * It is the callers responsibilty to call cJSON_Delete() on the returned cJSON object pointer.
 */
extern "C" cJSON *_model_af_event_exposure_subsc_generate_response(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t *af_events_notifications)
{
    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(af_event_exposure_subsc);

    /* copy AfEventExposureSubsc */
    std::shared_ptr<AfEventExposureSubsc > resp(new AfEventExposureSubsc(*obj));
    
    /* Add notifications */
    if (af_events_notifications && !ogs_list_empty(af_events_notifications)) {
        data_collection_lnode_t *node;
        ogs_list_for_each(af_events_notifications, node) {
            const typename fiveg_mag_reftools::remove_std_optional<AfEventExposureSubsc::EventNotifsItemType>::type &notif = *reinterpret_cast<const typename fiveg_mag_reftools::remove_std_optional<AfEventExposureSubsc::EventNotifsItemType>::type *>(node->object);
            resp->addEventNotifs(AfEventExposureSubsc::EventNotifsItemType(notif));
        }
    }

    /* return the JSON */
    fiveg_mag_reftools::CJson json(resp->toJSON(true));
    return json.exportCJSON();
}

/** Get the JSON for an AfEventExposureNotif callback request which includes the given notifications
 *
 * If af_events_notifications is NULL or empty then there are no event notifications to include and NULL will be returned.
 * It is the callers responsibilty to call cJSON_Delete() on the returned cJSON object pointer.
 */
extern "C" cJSON *_model_af_event_exposure_subsc_generate_notification(const data_collection_model_af_event_exposure_subsc_t *af_event_exposure_subsc, ogs_list_t *af_events_notifications)
{
    if (!af_events_notifications || ogs_list_empty(af_events_notifications)) return NULL;

    const std::shared_ptr<AfEventExposureSubsc > &obj = *reinterpret_cast<const std::shared_ptr<AfEventExposureSubsc >*>(af_event_exposure_subsc);

    std::shared_ptr<AfEventExposureNotif> notif(new AfEventExposureNotif());

    notif->setNotifId(obj->getNotifId());

    data_collection_lnode_t *node;
    ogs_list_for_each(af_events_notifications, node) {
        notif->addEventNotifs(AfEventExposureNotif::EventNotifsItemType(*reinterpret_cast<const typename fiveg_mag_reftools::remove_std_optional<AfEventExposureNotif::EventNotifsItemType>::type*>(node->object)));
    }

    fiveg_mag_reftools::CJson json(notif->toJSON(true));
    return json.exportCJSON();
}
